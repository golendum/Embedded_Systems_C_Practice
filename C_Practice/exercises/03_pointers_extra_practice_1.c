/*
 * EXERCISE 3: Pointers Extra Practice (Hard)
 * Topics: Advanced pointer operations, pointers to pointers, function pointers
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Problem 1: Pointers to pointers
void problem_1() {
    printf("--- Problem 1: Pointers to Pointers ---\n");
    int value = 42;
    int *ptr = &value;
    int **ptr_ptr = &ptr;
    
    // TODO: Modify value using ptr_ptr and print all three values
    **ptr_ptr = 100;
    printf("Before: value = %d\n", value);
    printf("Before: ptr = %d\n", *ptr);
    printf("Before: ptr_ptr = %d\n", **ptr_ptr);
    
    // TODO: Change what ptr points to
    int other_value = 200;
    *ptr = other_value;
    printf("After: value = %d\n", value);
    printf("After: ptr = %d\n", *ptr);
    printf("After: ptr_ptr = %d\n", **ptr_ptr);
    
}

// Problem 2: Array of pointers and pointer swapping
void swap_pointers(int **a, int **b) {
    // TODO: Swap what two pointers point to
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void problem_2() {
    printf("\n--- Problem 2: Array of Pointers ---\n");
    int x = 10, y = 20, z = 30;
    int *ptr_array[] = {&x, &y, &z};
    
    // TODO: Print initial values through pointers
    printf("Initial Array: [ %d, %d, %d ]\n", *ptr_array[0], *ptr_array[1], *ptr_array[2]);
    
    // TODO: Swap first and last pointers using swap_pointers
    swap_pointers(&ptr_array[0], &ptr_array[2]);
    printf("Final Array: [ %d, %d, %d ]\n", *ptr_array[0], *ptr_array[1], *ptr_array[2]);

}

// Problem 3: Function pointers and operations
typedef int (*operation_func)(int, int);

int add(int a, int b) {
    // TODO: Implement addition
    return (a + b);
}

int subtract(int a, int b) {
    // TODO: Implement subtraction
    return (a - b);
}

int multiply(int a, int b) {
    // TODO: Implement multiplication
    return (a * b);
}

void problem_3() {
    printf("\n--- Problem 3: Function Pointers ---\n");
    int a = 15, b = 3;
    
    operation_func ops[] = {add, subtract, multiply};
    const char *op_names[] = {"add", "subtract", "multiply"};
    
    // TODO: Call each operation through function pointers and print results
    for (int i = 0; i < 3; i++) {
        int result = ops[i](a, b);
        printf("%s: a & b = %d\n", op_names[i], ops[i](a, b));
    }
}

// Problem 4: Complex struct pointer operations
typedef struct {
    uint8_t *data;
    uint16_t length;
} Buffer;

typedef struct {
    Buffer *buffers;
    uint8_t count;
} BufferManager;

void problem_4() {
    printf("\n--- Problem 4: Nested Struct Pointers ---\n");
    
    uint8_t buf1[] = {0xAA, 0xBB, 0xCC};
    uint8_t buf2[] = {0xDD, 0xEE};
    
    Buffer buffers[] = {
        {buf1, 3},
        {buf2, 2}
    };
    
    BufferManager mgr = {buffers, 2};
    BufferManager *mgr_ptr = &mgr;
    
    // TODO: Access and print data from first buffer through manager pointer
    //printf("((mgr_ptr -> buffers + 1) -> data)[0] = 0x%02X\n", ((mgr_ptr -> buffers + 1) -> data)[0] );
    printf("1st Buffer Data: [ 0x%02X, 0x%02X, 0x%02X ]\n", ((mgr_ptr -> buffers) -> data)[0], ((mgr_ptr -> buffers) -> data)[1], ((mgr_ptr -> buffers) -> data)[2] );
    
    // TODO: Access and print data from second buffer through manager pointer
    printf("2nd Buffer Data: [ 0x%02X, 0x%02X ]\n", ((mgr_ptr -> buffers + 1) -> data)[0], ((mgr_ptr -> buffers + 1) -> data)[1] );
}

// Problem 5: Pointer arithmetic with structs and casting
typedef struct {
    uint16_t reg_a;
    uint16_t reg_b;
    uint16_t reg_c;
} RegisterBank;

void problem_5() {
    printf("\n--- Problem 5: Pointer Arithmetic and Casting ---\n");
    
    RegisterBank regs = {0x1111, 0x2222, 0x3333};
    uint16_t *reg_ptr = (uint16_t *)&regs;
    
    printf("Initial: reg_a=0x%04X, reg_b=0x%04X, reg_c=0x%04X\n", 
           regs.reg_a, regs.reg_b, regs.reg_c);
    
    // TODO: Increment each register by modifying through pointer
    *(reg_ptr) += 1;
    *(reg_ptr + 1) += 1;
    *(reg_ptr + 2) += 1;
    
    printf("After modification: reg_a=0x%04X, reg_b=0x%04X, reg_c=0x%04X\n", 
           regs.reg_a, regs.reg_b, regs.reg_c);
    
    // TODO: Calculate and print the total size through pointer arithmetic
    size_t arr_length = sizeof(regs) / sizeof(uint16_t);
    size_t total_size = (uint8_t*)(reg_ptr + arr_length) - (uint8_t*)(reg_ptr);

    printf("The total size of the buffer = %d bytes\n", total_size);
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    problem_5();
    return 0;
}
