/*
 * EXERCISE 3: Pointers and Memory
 * Topics: Pointers, addresses, dereferencing, arrays
 */

#include <stdio.h>
#include <stdint.h>

// Problem 1: Understand pointers
void problem_1() {
    printf("--- Problem 1: Pointer Basics ---\n");
    int value = 100;
    int *ptr = &value;
    
    // TODO: Print the value using direct variable
    // TODO: Print the value using pointer dereference (*ptr)
    // TODO: Print the address of value using &value
    // TODO: Print the pointer value directly
}

// Problem 2: Pointer arithmetic
void problem_2() {
    printf("\n--- Problem 2: Pointer Arithmetic ---\n");
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array;  // Points to first element
    
    // TODO: Print each array element using pointer arithmetic
    // Hint: array[0] is same as *ptr
    //       array[1] is same as *(ptr + 1)
    // Try a loop from 0 to 4
}

// Problem 3: Pass by reference
void modify_value(int *ptr) {
    // TODO: Modify the value that ptr points to
    *ptr = 999;
}

void problem_3() {
    printf("\n--- Problem 3: Pass by Reference ---\n");
    int x = 42;
    printf("Before: x = %d\n", x);
    modify_value(&x);
    printf("After: x = %d\n", x);
}

// Problem 4: Struct pointers (hardware register simulation)
typedef struct {
    uint8_t status;
    uint8_t control;
    uint16_t data;
} RegisterSet;

void problem_4() {
    printf("\n--- Problem 4: Struct Pointers ---\n");
    RegisterSet reg;
    RegisterSet *reg_ptr = &reg;
    
    // TODO: Set register values using pointer
    // - Set status to 0x01
    // - Set control to 0x80
    // - Set data to 0x1234
    
    // Hint: Use (*reg_ptr).member or reg_ptr->member
    
    // TODO: Print all values using the pointer
}

// Problem 5: Void pointers and casting
void problem_5() {
    printf("\n--- Problem 5: Void Pointers ---\n");
    
    int int_value = 255;
    uint8_t byte_value = 42;
    
    void *generic_ptr = &int_value;
    // TODO: Cast to int* and print the value
    
    generic_ptr = &byte_value;
    // TODO: Cast to uint8_t* and print the value
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    problem_5();
    return 0;
}
