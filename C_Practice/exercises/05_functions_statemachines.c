/*
 * EXERCISE 5: Functions and State Machines
 * Topics: Function pointers, callbacks, state machine implementation
 * Very relevant for embedded systems!
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Problem 1: Basic function implementation
// Simulate a simple LED control system
typedef enum {
    LED_OFF = 0,
    LED_ON = 1,
    LED_BLINKING = 2
} LEDState;

typedef struct {
    LEDState state;
    uint8_t brightness;  // 0-255
} LEDControl;

// TODO: Implement these functions:
// - void set_led_state(LEDControl *led, LEDState new_state)
// - void set_brightness(LEDControl *led, uint8_t brightness)
// - const char* get_led_status(LEDControl *led)
// - void print_led_info(LEDControl *led)

void problem_1() {
    printf("--- Problem 1: LED Control Functions ---\n");
    LEDControl led;
    led.state = LED_OFF;
    led.brightness = 0;
    
    // TODO: Call your functions:
    // - Set LED to ON
    // - Set brightness to 200
    // - Print LED info

    led.state = LED_ON;
    led.brightness = 200;
    printf("The LED state is %d\n", led.state);
    printf("The LED brightness is %d\n", led.brightness);
}

// Problem 2: State machine for a simple button handler
typedef enum {
    BUTTON_STATE_IDLE = 0,
    BUTTON_STATE_PRESSED = 1,
    BUTTON_STATE_HELD = 2,
    BUTTON_STATE_RELEASED = 3
} ButtonState;

typedef struct {
    ButtonState current_state;
    uint32_t press_count;
    uint32_t hold_time_ms;
} ButtonHandler;

void problem_2() {
    printf("\n--- Problem 2: Button State Machine ---\n");
    ButtonHandler button;
    button.current_state = BUTTON_STATE_IDLE;
    button.press_count = 0;
    button.hold_time_ms = 0;
    
    // TODO: Implement state transitions:
    // 1. Simulate button press: IDLE -> PRESSED
    button.current_state = BUTTON_STATE_PRESSED;
    button.press_count++;
    printf("Button state: %d\n", button.current_state);
    printf("Button press count: %d\n", button.press_count);
    // 2. Simulate button hold: PRESSED -> HELD
    button.current_state = BUTTON_STATE_HELD;
    printf("Button state: %d\n", button.current_state);
    printf("Button press count: %d\n", button.press_count);
    // 3. Simulate button release: HELD -> RELEASED
    button.current_state = BUTTON_STATE_RELEASED;
    printf("Button state: %d\n", button.current_state);
    printf("Button press count: %d\n", button.press_count);
    // 4. Return to idle: RELEASED -> IDLE
    button.current_state = BUTTON_STATE_IDLE;
    printf("Button state: %d\n", button.current_state);
    printf("Button press count: %d\n", button.press_count);
    
    // After each transition, print the state and press_count
}

// Problem 3: Function pointers and callbacks
typedef int (*CompareFunc)(int a, int b);

// TODO: Implement these comparison functions:
// - int compare_less_than(int a, int b)
int compare_less_than(int a, int b) {
    return (a < b);
}

// - int compare_greater_than(int a, int b)
int compare_greater_than(int a, int b) {
    return (a > b);
}

// - int compare_equal(int a, int b)
int compare_equal(int a, int b) {
    return (a == b);
}

// TODO: Implement this function that uses a callback:
// - int apply_comparison(int a, int b, CompareFunc compare)
int apply_comparison(int a, int b, CompareFunc compare) {
    return compare(a, b);
}

void problem_3() {
    printf("\n--- Problem 3: Function Pointers and Callbacks ---\n");
    
    int x = 21, y = 20;
    
    // TODO: Call apply_comparison with different comparison functions
    // - apply_comparison(x, y, compare_less_than)
    int x_less_than_y = apply_comparison(x, y, compare_less_than);
    printf("x less than y: %d\n", x_less_than_y);
    // - apply_comparison(x, y, compare_greater_than)
    int x_greater_than_y = apply_comparison(x, y, compare_greater_than);
    printf("x greater than y: %d\n", x_greater_than_y);
    // - apply_comparison(x, y, compare_equal)
    int x_equal_to_y = apply_comparison(x, y, compare_equal);
    printf("x equal to y: %d\n", x_equal_to_y);
}

// Problem 4: Simple UART message handler
typedef struct {
    uint8_t buffer[64];
    uint8_t length;
    uint8_t is_ready;
} UARTMessage;

// TODO: Implement these functions:
// - void uart_init_message(UARTMessage *msg)
void uart_init_message(UARTMessage *msg) {
    memset(msg -> buffer, 0, sizeof(msg -> buffer));
    msg -> length = 0;
    msg -> is_ready = 0;
    printf("Message initialized.\n");
}

// - void uart_append_byte(UARTMessage *msg, uint8_t byte)
void uart_append_byte(UARTMessage *msg, uint8_t byte) {
    if (msg != NULL && msg -> length < sizeof(msg -> buffer)) {
        msg -> buffer[msg -> length] = byte;
        if (msg -> buffer[msg -> length] == '\0') {
            printf("Message ready to send.\n");
            msg -> is_ready = 1;
        }
        msg -> length ++;
    }
}

// - void uart_send_message(UARTMessage *msg)
void uart_send_message(UARTMessage *msg) {
    if (msg == NULL) return;
    if (msg -> is_ready) {
        printf("Sent: ");
        for (int i = 0; i < msg -> length; i++) {
            // In real embedded software, this would be HAL_send or another function like that
            putchar(msg -> buffer[i]);
        }
        putchar('\n');
    }
}

// - void uart_print_message(UARTMessage *msg)
void uart_print_message(UARTMessage *msg) {
    if (msg == NULL) return;
    int i = 0;
    printf("Message: ");
    while (msg -> buffer[i] != '\0') {
        putchar(msg -> buffer[i]);
        i++;
    }
    putchar('\n');
}


void problem_4() {
    printf("\n--- Problem 4: UART Message Handler ---\n");
    UARTMessage msg;
    
    // TODO: Initialize message
    uart_init_message(&msg);
    // Append some bytes: 'H', 'i', '!', '\0'
    uart_append_byte(&msg, 'H');
    uart_append_byte(&msg, 'i');
    uart_append_byte(&msg, '!');
    uart_append_byte(&msg, '\0');
    // Print the message
    uart_print_message(&msg);
    // Send the message
    uart_send_message(&msg);
}

// Problem 5: Timer callback system
typedef void (*TimerCallback)(void);

typedef struct {
    TimerCallback callback;
    uint32_t interval_ms;
    uint32_t elapsed_ms;
    uint8_t is_running;
} Timer;

// TODO: Implement:
// - void timer_init(Timer *timer, TimerCallback cb, uint32_t interval)
// - void timer_start(Timer *timer)
// - void timer_stop(Timer *timer)
// - void timer_tick(Timer *timer)  // Call this periodically
// - int timer_is_expired(Timer *timer)

void my_timer_callback(void) {
    printf("Timer callback executed!\n");
}

void timer_init(Timer *timer, TimerCallback cb, uint32_t interval) {
    if (timer == NULL) return;
    timer -> callback = cb;
    timer -> interval_ms = interval;
    timer -> elapsed_ms = 0;
    timer -> is_running = 0;
    printf("Timer initialized.\n");
}

void timer_start(Timer *timer) {
    if (timer == NULL) return;
    timer -> is_running = 1;
    timer -> elapsed_ms = 0; // Reset upon start
    printf("Timer started!\n");
}

void timer_stop(Timer *timer) {
    if (timer == NULL) return;
    timer -> is_running = 0;
    printf("Timer stopped!\n");
}

void timer_tick(Timer *timer) {
    if (timer != NULL && timer -> is_running) {
        timer -> elapsed_ms += 200;
        printf("Timer value: %d\n", timer -> elapsed_ms);
    }
}

int timer_is_expired(Timer *timer) {
    return !(timer -> elapsed_ms < timer -> interval_ms);
}

void problem_5() {
    printf("\n--- Problem 5: Timer with Callback ---\n");
    Timer timer;
    
    // TODO: Initialize timer with 1000ms interval and callback
    timer_init(&timer, my_timer_callback, 1000);
    // TODO: Start timer
    timer_start(&timer);
    // TODO: Simulate 5 ticks (200ms each)
    // TODO: Check if timer expired after each tick

    while (1) {
        timer_tick(&timer);
        if (timer_is_expired(&timer)) {
            timer_stop(&timer);
            break;
        }
    }
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    problem_5();
    return 0;
}
