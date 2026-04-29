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
}

// TODO: Implement gpio_write_pin()
// Purpose: Set a GPIO pin HIGH
void gpio_write_pin(GPIOPort *port, uint8_t pin, uint8_t value) {
    // If value is 1, set the bit
    // If value is 0, clear the bit
}

// TODO: Implement gpio_read_pin()
// Purpose: Read a GPIO pin state
uint8_t gpio_read_pin(GPIOPort *port, uint8_t pin) {
    // Return 1 if pin is high, 0 if low
    return 0;
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
}

// TODO: Implement gpio_simulate_interrupt()
// Simulates an interrupt occurring on a pin
void gpio_simulate_interrupt(GPIOPort *port, uint8_t pin) {
    if (port->interrupt_en & (1 << pin)) {
        port->interrupt_flag |= (1 << pin);
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
    
    // 2. Write to output pins
    printf("\nStep 2: Write to GPIO pins\n");
    // TODO: Set PIN_0 HIGH
    // TODO: Set PIN_1 HIGH  
    // TODO: Set PIN_2 LOW
    printf("Pins set!\n");
    
    // 3. Read from input pins
    printf("\nStep 3: Read GPIO input pins\n");
    // TODO: Simulate some input values on PIN_3, PIN_4, PIN_5
    // Hint: Set GPIO_PORTA.gpio_in directly for simulation
    
    // TODO: Read and print each pin value
    
    // 4. Test interrupts
    printf("\nStep 4: Test interrupt handling\n");
    // TODO: Enable interrupts on PIN_5
    // TODO: Simulate an interrupt on PIN_5
    
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
// - void led_toggle(LEDController *ctrl)
// - void led_blink_pattern(LEDController *ctrl, uint32_t num_blinks)
// - void led_button_handler(LEDController *ctrl)  // Handle button press

void bonus_led_blinking() {
    printf("=== BONUS: LED Blinking with Button Control ===\n\n");
    
    LEDController led;
    
    // TODO: Initialize LED controller
    // TODO: Simulate button press and handle LED blinking
}

int main() {
    project_1_gpio_control();
    
    // Uncomment when ready:
    // bonus_led_blinking();
    
    return 0;
}
