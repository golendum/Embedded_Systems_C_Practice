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
    sensor.id = 1;
    sensor.temperature = 2580;
    sensor.status = 0x01;
    
    // TODO: Print all fields
    printf("Sensor size: %zu bytes\n", sizeof(SensorData));
    printf("Sensor ID: %d\n", sensor.id);
    printf("Sensor Temperature: %d\n", sensor.temperature);
    printf("Sensor Status: 0x%02X\n", sensor.status);
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

    ctrl.enable = 1;
    ctrl.ready = 1;
    ctrl.error = 0;
    
    // TODO: Print each field
    printf("Control register size: %zu bytes\n", sizeof(ControlRegister));
    printf("Control register enable: %d\n", ctrl.enable);
    printf("Control register ready: %d\n", ctrl.ready);
    printf("Control register error: %d\n", ctrl.error);
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
    #include <stddef.h>

    printf("The offset of byte 1 = %u\n", offsetof(TestStruct, byte1));
    printf("The offset of word = %u\n", offsetof(TestStruct, word));
    printf("The offset of byte 1 = %u\n", offsetof(TestStruct, byte2));
}

// Problem 4: Array of structs
void problem_4() {
    printf("\n--- Problem 4: Arrays of Structs ---\n");
    
    SensorData sensors[3];
    
    // TODO: Initialize array with:
    // sensors[0]: id=0, temp=2500, status=1
    // sensors[1]: id=1, temp=2650, status=1
    // sensors[2]: id=2, temp=2400, status=0

    sensors[0].id = 0; sensors[0].temperature = 2500; sensors[0].status = 1;
    sensors[1].id = 1; sensors[1].temperature = 2650; sensors[1].status = 1;
    sensors[2].id = 2; sensors[2].temperature = 2400; sensors[2].status = 0;
    
    // TODO: Loop through and print all sensors
    // Format: "Sensor ID: X, Temp: X.XXC, Status: X"
    int num_sensors = sizeof(sensors) / sizeof(SensorData);
    printf("Number of sensors = %d\n", num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor ID: %d, Temp: %.2fC, Status: %d\n", sensors[i].id, ( (float) sensors[i].temperature / 100.00 ), sensors[i].status);
    }
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

    // Bit definitions for control register
    #define CTRL_ENABLE  (1 << 0) // Bit 0: Enable
    #define CTRL_CONFIG  (1 << 1) // Bit 1: Configure
    #define CTRL_MODE_SEL(n) ((n & 0x03) << 2) // Bits 2-3: Mode

    peripheral.control = CTRL_ENABLE | CTRL_CONFIG | CTRL_MODE_SEL(2); // Set enable, configure, and mode = 2
    peripheral.status = 1;
    peripheral.data = 0xABC;
    peripheral.timestamp = 0x1234;
    
    printf("Peripheral size: %zu bytes\n", sizeof(HardwarePeripheral));
    printf("Peripheral control register: %d\n", peripheral.control); //should be 0b1011
    printf("Peripheral status register: %d\n", peripheral.status);
    printf("Peripheral data register: %02X\n", peripheral.data);
    printf("Peripheral timestamp register: %02X\n", peripheral.timestamp);
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
