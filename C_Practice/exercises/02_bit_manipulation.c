/*
 * EXERCISE 2: Bit Manipulation
 * Topics: Bitwise operators, bit flags, register access patterns
 * CRITICAL for embedded systems!
 */

#include <stdio.h>
#include <stdint.h>

// Helper function to print binary representation
void print_binary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

// Problem 1: Understand bitwise operators
void problem_1() {
    printf("--- Problem 1: Bitwise Operators ---\n");
    uint8_t a = 0b11110000;  // 240
    uint8_t b = 0b10101010;  // 170
    
    printf("a = ");
    print_binary(a);
    printf(" (0x%02X)\n", a);
    
    printf("b = ");
    print_binary(b);
    printf(" (0x%02X)\n", b);
    
    // TODO: Calculate and print:
    // - a & b (AND)
    // - a | b (OR)
    // - a ^ b (XOR)
    // - ~a (NOT)
    // - a << 1 (left shift)
    // - a >> 1 (right shift)
}

// Problem 2: Set, clear, and toggle individual bits
void problem_2() {
    printf("\n--- Problem 2: Bit Manipulation Functions ---\n");
    uint8_t flags = 0b00000000;
    
    // Define which bit positions we care about
    #define BIT_0 (1 << 0)
    #define BIT_3 (1 << 3)
    #define BIT_7 (1 << 7)
    
    // TODO: Implement these operations:
    // 1. Set BIT_0 (hint: use |=)
    // 2. Set BIT_3 (hint: use |=)
    // 3. Clear BIT_0 (hint: use &= with ~)
    // 4. Toggle BIT_7 (hint: use ^=)
    
    // TODO: After each operation, print the binary representation
}

// Problem 3: Check if specific bits are set
void problem_3() {
    printf("\n--- Problem 3: Bit Testing ---\n");
    uint8_t status_register = 0b10110101;  // Simulated hardware register
    
    #define BIT_READY    (1 << 0)
    #define BIT_ERROR    (1 << 1)
    #define BIT_BUSY     (1 << 2)
    #define BIT_ENABLED  (1 << 7)
    
    // TODO: Check each flag and print if it's set or cleared
    // Hint: Use (register & BIT_FLAG) to check
    // Example: if (status_register & BIT_READY) { printf("Ready\n"); }
}

// Problem 4: Extract nibbles and bytes
void problem_4() {
    printf("\n--- Problem 4: Extract Nibbles ---\n");
    uint8_t byte_value = 0xA5;  // 10100101
    
    // TODO: Extract the high nibble (upper 4 bits)
    // Hint: Shift right by 4
    
    // TODO: Extract the low nibble (lower 4 bits)
    // Hint: Mask with 0x0F
    
    // TODO: Print both nibbles in hex format
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    return 0;
}
