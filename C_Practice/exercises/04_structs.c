/*
 * EXERCISE 4: Structs and Hardware Registers
 * Topics: Structs, bit fields, memory layout
 * Directly applicable to embedded systems!
 */

#include <stdio.h>
#include <stdint.h>

// Problem 1: Basic struct
typedef struct {
    uint8_t id;
    uint16_t temperature;
    uint8_t status;
} SensorData;

void problem_1() {
    printf("--- Problem 1: Basic Structs ---\n");
    SensorData sensor;
    
    // TODO: Initialize sensor data
    // - id = 1
    // - temperature = 2580 (25.80°C in centigrade * 100)
    // - status = 0x01
    
    // TODO: Print all fields
    printf("Sensor size: %zu bytes\n", sizeof(SensorData));
}

// Problem 2: Bit fields (compact register representation)
typedef struct {
    uint8_t enable : 1;      // Bit 0
    uint8_t ready : 1;       // Bit 1
    uint8_t error : 1;       // Bit 2
    uint8_t reserved : 5;    // Bits 3-7
} ControlRegister;

void problem_2() {
    printf("\n--- Problem 2: Bit Fields ---\n");
    ControlRegister ctrl;
    
    // TODO: Set individual fields
    // - enable = 1
    // - ready = 1
    // - error = 0
    
    // TODO: Print each field
    printf("Control register size: %zu bytes\n", sizeof(ControlRegister));
    printf("This is much better than bit manipulation for readability!\n");
}

// Problem 3: Memory layout of structs
void problem_3() {
    printf("\n--- Problem 3: Struct Memory Layout ---\n");
    
    typedef struct {
        uint8_t byte1;
        uint16_t word;
        uint8_t byte2;
    } TestStruct;
    
    TestStruct test;
    test.byte1 = 0x11;
    test.word = 0x2222;
    test.byte2 = 0x33;
    
    printf("TestStruct size: %zu bytes\n", sizeof(TestStruct));
    printf("Note: There may be padding between fields!\n");
    
    // TODO: Print offsets of each member using offsetof macro
    // #include <stddef.h> for offsetof
    // Hint: offsetof(TestStruct, byte1)
}

// Problem 4: Array of structs
void problem_4() {
    printf("\n--- Problem 4: Arrays of Structs ---\n");
    
    SensorData sensors[3];
    
    // TODO: Initialize array with:
    // sensors[0]: id=0, temp=2500, status=1
    // sensors[1]: id=1, temp=2650, status=1
    // sensors[2]: id=2, temp=2400, status=0
    
    // TODO: Loop through and print all sensors
    // Format: "Sensor ID: X, Temp: X.XXC, Status: X"
}

// Problem 5: Simulate hardware register structure
// This simulates a typical microcontroller peripheral register set
typedef struct {
    uint8_t control;      // Offset 0x00
    uint8_t status;       // Offset 0x01
    uint16_t data;        // Offset 0x02-0x03
    uint32_t timestamp;   // Offset 0x04-0x07
} HardwarePeripheral;

void problem_5() {
    printf("\n--- Problem 5: Hardware Register Simulation ---\n");
    
    HardwarePeripheral peripheral;
    
    // TODO: Initialize peripheral registers
    // Set control to enable and configure (use bit manipulation)
    // Set status initial value
    // Set data value
    // Set timestamp
    
    printf("Peripheral size: %zu bytes\n", sizeof(HardwarePeripheral));
    printf("Register structure initialized!\n");
}

int main() {
    problem_1();
    problem_2();
    problem_3();
    problem_4();
    problem_5();
    return 0;
}
