/*
 * EXERCISE 1: Basic Concepts
 * Topics: printf, scanf, data types, variables
 */

#include <stdio.h>
#include <stdint.h>

// Problem 1: Print integer values
void problem_1() {
    printf("--- Problem 1: Basic Output ---\n");
    int value = 42;
    // TODO: Print the value using printf
    // Expected output: value = 42
}

// Problem 2: Read user input
void problem_2() {
    printf("\n--- Problem 2: User Input ---\n");
    printf("Enter an integer: ");
    int input;
    // TODO: Read integer from user
    // TODO: Print "You entered: X"
}

// Problem 3: Understand data types and sizes
void problem_3() {
    printf("\n--- Problem 3: Data Type Sizes ---\n");
    // TODO: Print the size of each type using sizeof()
    // Types to check: char, short, int, long, float, double
    // uint8_t, uint16_t, uint32_t, uint64_t
    // Expected format: "char size: X bytes"
}

// Problem 4: Simple arithmetic
void problem_4() {
    printf("\n--- Problem 4: Arithmetic Operations ---\n");
    int a = 15, b = 4;
    // TODO: Calculate and print:
    // - a + b
    // - a - b
    // - a * b
    // - a / b
    // - a % b (modulo)
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    return 0;
}
