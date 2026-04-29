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
    printf("value = %d\n", value);
    // Expected output: value = 42
}

// Problem 2: Read user input
void problem_2() {
    printf("\n--- Problem 2: User Input ---\n");
    printf("Enter an integer: ");
    int input;
    // TODO: Read integer from user
    scanf("%d", &input);
    // TODO: Print "You entered: X"
    printf("You entered: %d\n", input);
}

// Problem 3: Understand data types and sizes
void problem_3() {
    printf("\n--- Problem 3: Data Type Sizes ---\n");
    // TODO: Print the size of each type using sizeof()
    // Types to check: char, short, int, long, float, double
    // uint8_t, uint16_t, uint32_t, uint64_t

    int char_size = sizeof(char);
    int short_size = sizeof(short);
    int int_size = sizeof(int);
    int long_size = sizeof(long);
    int float_size = sizeof(float);
    int double_size = sizeof(double);
    int uint8_t_size = sizeof(uint8_t);
    int uint16_t_size = sizeof(uint16_t);
    int uint32_t_size = sizeof(uint32_t);
    int uint64_t_size = sizeof(uint64_t);

    // Expected format: "char size: X bytes"
    printf("char size: %d bytes\n", char_size);
    printf("short size: %d bytes\n", short_size);
    printf("int size: %d bytes\n", int_size);
    printf("long size: %d bytes\n", long_size);
    printf("float size: %d bytes\n", float_size);
    printf("double size: %d bytes\n", double_size);
    printf("uint8_t size: %d bytes\n", uint8_t_size);
    printf("uint16_t size: %d bytes\n", uint16_t_size);
    printf("uint32_t size: %d bytes\n", uint32_t_size);
    printf("uint64_t size: %d bytes\n", uint64_t_size);
}

// Problem 4: Simple arithmetic
void problem_4() {
    printf("\n--- Problem 4: Arithmetic Operations ---\n");
    int a = 15, b = 4;
    // TODO: Calculate and print:
    printf("%d\n", (- a + b)); // - a + b
    printf("%d\n", (- a - b)); // - a - b
    printf("%d\n", (- a * b)); // - a * b
    printf("%d\n", (- a / b)); // - a / b
    printf("%d\n", (- a % b)); // - a % b
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    return 0;
}
