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
    printf("value = %d\n", value);
    // TODO: Print the value using pointer dereference (*ptr)
    printf("*ptr = %d\n", (*ptr));
    // TODO: Print the address of value using &value
    printf("&value = %d\n", &value);
    // TODO: Print the pointer value directly
    printf("ptr = %d\n", ptr);
}

// Problem 2: Pointer arithmetic
void problem_2() {
    printf("\n--- Problem 2: Pointer Arithmetic ---\n");
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array;  // Points to first element

    int arr_size = (sizeof(array) / sizeof(int));
    printf("Array size = %d\n", arr_size);
    
    printf("Array:\n[ ");
    // TODO: Print each array element using pointer arithmetic
    for (int i = 0; i < arr_size; i++) {
        printf("%d", *(ptr + i));
        if ((i + 1) == arr_size) { printf(" ]"); }
        else { printf(", "); }
    }
    printf("\n");
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
    // Set status to 0x01
    reg_ptr -> status = 0x01;
    // Set control to 0x80
    reg_ptr -> control = 0x80;
    // Set data to 0x1234
    reg_ptr -> data = 0x1234;
    
    // TODO: Print all values using the pointer
    printf("status = %d\n", reg_ptr -> status);
    printf("status = 0x%02X\n", reg_ptr -> status);
    printf("control = %d\n", reg_ptr -> control);
    printf("control = 0x%02X\n", reg_ptr -> control);
    printf("data = %d\n", reg_ptr -> data);
    printf("data = 0x%02X\n", reg_ptr -> data);
}

// Problem 5: Void pointers and casting
void problem_5() {
    printf("\n--- Problem 5: Void Pointers ---\n");
    
    int int_value = 255;
    uint8_t byte_value = 42;
    
    void *generic_ptr = &int_value;
    // TODO: Cast to int* and print the value
    printf("int value = %d\n", *(int*)generic_ptr);
    
    generic_ptr = &byte_value;
    // TODO: Cast to uint8_t* and print the value
    printf("byte value = %d\n", *(uint8_t*)generic_ptr);

}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    problem_5();
    return 0;
}
