/*
 * EMBEDDED SYSTEMS PROJECT 1: Simple GPIO and Register Control
 * Topics: Memory-mapped registers, GPIO control, interrupt handlers
 * 
 * This simulates controlling GPIO pins and interrupts like you'd do
 * on a real microcontroller (STM32, PIC, etc.)
 */

#include <stdio.h>
#include <stdint.h>

// ============ REGISTER DEFINITIONS ============
// In real hardware, these would be at specific memory addresses

typedef struct {
    volatile uint32_t gpio_mode;      // Configure GPIO mode (input/output)
    volatile uint32_t gpio_out;       // Write to GPIO pins
    volatile uint32_t gpio_in;        // Read from GPIO pins
    volatile uint8_t interrupt_flag;  // Interrupt status
    volatile uint8_t interrupt_en;    // Interrupt enable
} GPIOPort;

// Simulate hardware registers at specific "memory addresses"
GPIOPort GPIO_PORTA;
GPIOPort GPIO_PORTB;

// ============ GPIO MODE DEFINITIONS ============
#define GPIO_MODE_INPUT   0b00
#define GPIO_MODE_OUTPUT  0b01
#define GPIO_MODE_ALT     0b10
#define GPIO_MODE_ANALOG  0b11

#define GPIO_PIN_0  (1 << 0)
#define GPIO_PIN_1  (1 << 1)
#define GPIO_PIN_2  (1 << 2)
#define GPIO_PIN_3  (1 << 3)
#define GPIO_PIN_4  (1 << 4)
#define GPIO_PIN_5  (1 << 5)

// ============ FUNCTIONS TO IMPLEMENT ============

// TODO: Implement gpio_set_pin_mode()
// Purpose: Configure pin as input or output
// Hint: Set bits in gpio_mode register for the specified pin
void gpio_set_pin_mode(GPIOPort *port, uint8_t pin, uint8_t mode) {
    // gpio_mode uses 2 bits per pin
    // Pin 0 uses bits [1:0], Pin 1 uses bits [3:2], etc.
    uint8_t shift = 0;
    while ((pin >> shift) != 1) {
        shift++;
    }

    shift = shift * 2;
    // Clear original bits first (using a mask)
    port -> gpio_mode &= ~(0b11 << shift);

    // Set relevant pin bits to new mode
    port -> gpio_mode |= (mode << shift);    
}

// TODO: Implement gpio_write_pin()
// Purpose: Set a GPIO pin HIGH
void gpio_write_pin(GPIOPort *port, uint8_t pin, uint8_t value) {
    // If value is 1, set the bit
    if (value == 1) {
        port -> gpio_out |= pin;
    }

    // If value is 0, clear the bit
    else if (value == 0) {
        port -> gpio_out &= ~pin;
    }
}

// TODO: Implement gpio_read_pin()
// Purpose: Read a GPIO pin state
uint8_t gpio_read_pin(GPIOPort *port, uint8_t pin) {
    // Return 1 if pin is high, 0 if low
    return (port -> gpio_in & pin) ? 1 : 0;
}

// TODO: Implement interrupt handler
void gpio_interrupt_handler(GPIOPort *port) {
    printf("[INTERRUPT] GPIO interrupt triggered!\n");
    printf("Flag register: 0x%02X\n", port->interrupt_flag);
    
    // Clear the interrupt flag
    port->interrupt_flag = 0;
}

// TODO: Implement gpio_enable_interrupt()
void gpio_enable_interrupt(GPIOPort *port, uint8_t pin) {
    // Set interrupt enable bit for this pin
    port -> interrupt_en |= pin;
}

// TODO: Implement gpio_simulate_interrupt()
// Simulates an interrupt occurring on a pin
void gpio_simulate_interrupt(GPIOPort *port, uint8_t pin) {
    if (port->interrupt_en & pin) {
        port->interrupt_flag |= pin;
        gpio_interrupt_handler(port);
    }
}

// ============ MAIN PROGRAM ============

void project_1_gpio_control() {
    printf("=== EMBEDDED PROJECT 1: GPIO Control ===\n\n");
    
    // TODO: Complete the following tasks:
    
    // 1. Initialize GPIO Port A
    printf("Step 1: Initialize GPIO Port A\n");
    // TODO: Set pins 0-2 as outputs, pins 3-5 as inputs
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_0, GPIO_MODE_OUTPUT);
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_2, GPIO_MODE_OUTPUT);
    
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_3, GPIO_MODE_INPUT);
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_4, GPIO_MODE_INPUT);
    gpio_set_pin_mode(&GPIO_PORTA, GPIO_PIN_5, GPIO_MODE_INPUT);
    
    // 2. Write to output pins
    printf("\nStep 2: Write to GPIO pins\n");
    // TODO: Set PIN_0 HIGH
    gpio_write_pin(&GPIO_PORTA, GPIO_PIN_0, 1);
    // TODO: Set PIN_1 HIGH
    gpio_write_pin(&GPIO_PORTA, GPIO_PIN_1, 1);
    // TODO: Set PIN_2 LOW
    gpio_write_pin(&GPIO_PORTA, GPIO_PIN_2, 0);
    printf("Pins set!\n");
    
    // 3. Read from input pins
    printf("\nStep 3: Read GPIO input pins\n");
    // TODO: Simulate some input values on PIN_3 (high), PIN_4 (low), PIN_5 (high)
    // Hint: Set GPIO_PORTA.gpio_in directly for simulation
    GPIO_PORTA.gpio_in = (1 << 3) | (1 << 5);

    // TODO: Read and print each pin value
    printf("Pin 3 = %d\n", gpio_read_pin(&GPIO_PORTA, GPIO_PIN_3));
    printf("Pin 4 = %d\n", gpio_read_pin(&GPIO_PORTA, GPIO_PIN_4));
    printf("Pin 5 = %d\n", gpio_read_pin(&GPIO_PORTA, GPIO_PIN_5));
    

    // 4. Test interrupts
    printf("\nStep 4: Test interrupt handling\n");
    // TODO: Enable interrupts on PIN_5
    gpio_enable_interrupt(&GPIO_PORTA, GPIO_PIN_5);
    // TODO: Simulate an interrupt on PIN_5
    gpio_simulate_interrupt(&GPIO_PORTA, GPIO_PIN_5);
    
    printf("\n");
}

// ============ BONUS: Advanced GPIO Pattern ============

// Problem: Implement a simple LED blink pattern using GPIO
#define LED_PIN GPIO_PIN_0
#define BUTTON_PIN GPIO_PIN_3

typedef struct {
    GPIOPort *port;
    uint8_t led_pin;
    uint8_t button_pin;
    uint32_t blink_count;
    uint8_t is_blinking;
} LEDController;

// TODO: Implement:
// - void led_init(LEDController *ctrl, GPIOPort *port)
void led_init(LEDController *ctrl, GPIOPort *port) {
    ctrl -> port = port;
    ctrl -> led_pin = LED_PIN;
    ctrl -> button_pin = BUTTON_PIN;
    ctrl -> blink_count = 0;
    ctrl -> is_blinking = 0;

    gpio_set_pin_mode(ctrl -> port, ctrl -> led_pin, GPIO_MODE_OUTPUT);
    gpio_set_pin_mode(ctrl -> port, ctrl -> button_pin, GPIO_MODE_INPUT);
}

// - void led_toggle(LEDController *ctrl)
void led_toggle(LEDController *ctrl) {
    uint8_t led_state = gpio_read_pin(ctrl -> port, ctrl -> led_pin);
    gpio_write_pin(ctrl -> port, ctrl -> led_pin, !led_state);
}

// - void led_blink_pattern(LEDController *ctrl, uint32_t num_blinks)
void led_blink_pattern(LEDController *ctrl, uint32_t num_blinks) {
    while (ctrl -> blink_count < num_blinks) {
        led_toggle(ctrl);
        ctrl -> blink_count++;
    }
}

// - void led_button_handler(LEDController *ctrl)  // Handle button press
void led_button_handler(LEDController *ctrl) {
    printf("Button pressed! Starting LED blink pattern.\n");
    ctrl -> is_blinking = 1;
    led_blink_pattern(ctrl, 10);
    printf("Blinking finished!\n");
    ctrl -> is_blinking = 0;
}

void bonus_led_blinking() {
    printf("=== BONUS: LED Blinking with Button Control ===\n\n");
    
    LEDController led;
    
    // TODO: Initialize LED controller
    led_init(&led, &GPIO_PORTB);
    // TODO: Simulate button press and handle LED blinking
    GPIO_PORTB.gpio_in = (1 << 3);
    led_button_handler(&led);
    printf("Blink count: %d\n", led.blink_count);
}

int main() {
    project_1_gpio_control();
    
    // Uncomment when ready:
    bonus_led_blinking();
    
    return 0;
}
