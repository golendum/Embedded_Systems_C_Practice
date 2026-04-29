/*
 * EMBEDDED SYSTEMS PROJECT 2: CAN Bus Communication Simulator
 * Topics: Circular buffers, message queues, communication protocols
 * 
 * CAN (Controller Area Network) is THE protocol for automotive systems!
 * This simulates CAN message handling.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ============ CAN MESSAGE DEFINITION ============

typedef struct {
    uint32_t can_id;          // 11-bit or 29-bit identifier
    uint8_t dlc;              // Data Length Code (0-8)
    uint8_t data[8];          // CAN data bytes
    uint32_t timestamp;       // When message was received
} CANMessage;

// CAN Message priorities
#define CAN_PRIORITY_HIGH   0x100
#define CAN_PRIORITY_MED    0x200
#define CAN_PRIORITY_LOW    0x300

// ============ CIRCULAR BUFFER FOR CAN MESSAGES ============

#define CAN_RX_BUFFER_SIZE 32  // Size of circular buffer

typedef struct {
    CANMessage buffer[CAN_RX_BUFFER_SIZE];
    uint16_t head;  // Write pointer
    uint16_t tail;  // Read pointer
    uint16_t count; // Number of messages in buffer
} CANRxBuffer;

// ============ FUNCTIONS TO IMPLEMENT ============

// TODO: Implement can_buffer_init()
void can_buffer_init(CANRxBuffer *buf) {
    // Initialize buffer (set head, tail, count to 0)
}

// TODO: Implement can_buffer_push()
// Add a message to the buffer
uint8_t can_buffer_push(CANRxBuffer *buf, CANMessage *msg) {
    // If buffer is full, return 0 (failure)
    // Otherwise, add message at head position, increment head and count
    // Handle wrap-around when head reaches buffer size
    return 1;
}

// TODO: Implement can_buffer_pop()
// Remove and return a message from the buffer
uint8_t can_buffer_pop(CANRxBuffer *buf, CANMessage *msg) {
    // If buffer is empty, return 0 (failure)
    // Otherwise, get message from tail position, increment tail and decrement count
    // Handle wrap-around when tail reaches buffer size
    return 1;
}

// TODO: Implement can_buffer_is_empty()
uint8_t can_buffer_is_empty(CANRxBuffer *buf) {
    return buf->count == 0;
}

// TODO: Implement can_buffer_is_full()
uint8_t can_buffer_is_full(CANRxBuffer *buf) {
    return buf->count >= CAN_RX_BUFFER_SIZE;
}

// ============ CAN MESSAGE HANDLING ============

// TODO: Implement can_create_message()
// Create a CAN message with the given parameters
void can_create_message(CANMessage *msg, uint32_t id, uint8_t dlc, 
                       const uint8_t *data, uint32_t timestamp) {
    msg->can_id = id;
    msg->dlc = dlc > 8 ? 8 : dlc;
    memcpy(msg->data, data, msg->dlc);
    msg->timestamp = timestamp;
}

// TODO: Implement can_print_message()
void can_print_message(CANMessage *msg) {
    printf("CAN ID: 0x%03X, DLC: %d, Data: ", msg->can_id, msg->dlc);
    for (int i = 0; i < msg->dlc; i++) {
        printf("%02X ", msg->data[i]);
    }
    printf("(Timestamp: %u)\n", msg->timestamp);
}

// ============ CALLBACK SYSTEM FOR MESSAGE HANDLING ============

typedef void (*CANMessageHandler)(CANMessage *msg);

typedef struct {
    uint32_t can_id;
    CANMessageHandler handler;
} CANMessageFilter;

#define MAX_FILTERS 10

typedef struct {
    CANMessageFilter filters[MAX_FILTERS];
    uint8_t filter_count;
} CANFilterList;

// TODO: Implement can_register_handler()
void can_register_handler(CANFilterList *filters, uint32_t can_id, 
                         CANMessageHandler handler) {
    // Add a new filter to the list
    // If filter list is full, print error
}

// TODO: Implement can_dispatch_message()
// Find and call the handler for a message
void can_dispatch_message(CANFilterList *filters, CANMessage *msg) {
    // Loop through filters and find matching CAN ID
    // If found, call the handler
    // Otherwise, print "No handler for this message"
}

// ============ EXAMPLE MESSAGE HANDLERS ============

void handle_engine_status(CANMessage *msg) {
    printf("  [ENGINE STATUS] RPM: %d, Temp: %d°C\n", 
           (msg->data[0] << 8) | msg->data[1],
           msg->data[2]);
}

void handle_wheel_speed(CANMessage *msg) {
    printf("  [WHEEL SPEED] Front: %d, Rear: %d\n",
           (msg->data[0] << 8) | msg->data[1],
           (msg->data[2] << 8) | msg->data[3]);
}

void handle_battery_status(CANMessage *msg) {
    printf("  [BATTERY] Voltage: %d.%dV, Current: %dmA\n",
           msg->data[0], msg->data[1],
           (msg->data[2] << 8) | msg->data[3]);
}

// ============ MAIN PROJECT ============

void project_2_can_bus() {
    printf("=== EMBEDDED PROJECT 2: CAN Bus Communication ===\n\n");
    
    CANRxBuffer rx_buffer;
    CANFilterList filters;
    
    // TODO: Complete the following tasks:
    
    // 1. Initialize CAN buffer and filters
    printf("Step 1: Initialize CAN subsystem\n");
    // TODO: Initialize rx_buffer
    // TODO: Initialize filters
    // TODO: Register message handlers for engine, wheels, and battery
    
    // 2. Simulate receiving CAN messages
    printf("\nStep 2: Simulate receiving CAN messages\n");
    
    uint8_t engine_data[] = {0x12, 0x34, 0x55};  // RPM: 4660, Temp: 85°C
    uint8_t wheel_data[] = {0x00, 0x50, 0x00, 0x48};  // Front: 80, Rear: 72
    uint8_t battery_data[] = {0x0D, 0x80, 0x05, 0x00};  // 13.8V, 1280mA
    
    // TODO: Create CAN messages
    CANMessage engine_msg, wheel_msg, battery_msg;
    
    // TODO: Push messages to RX buffer
    
    // TODO: Pop messages from buffer and dispatch to handlers
    
    // 3. Test buffer full condition
    printf("\nStep 3: Test buffer overflow\n");
    // TODO: Fill buffer to capacity
    // TODO: Try to add one more message
    
    printf("\n");
}

// ============ BONUS: Message Filtering and Sorting ============

typedef struct {
    uint32_t can_id;
    uint8_t priority;
} CANMessagePriority;

// TODO: Implement priority queue insertion
void can_priority_insert(CANMessage *queue[], uint32_t *count, 
                        CANMessage *msg, uint8_t priority) {
    // Insert message into queue maintaining priority order
}

void bonus_priority_queue() {
    printf("=== BONUS: CAN Message Priority Queue ===\n\n");
    
    // TODO: Create priority queue and add messages with different priorities
}

int main() {
    project_2_can_bus();
    
    // Uncomment when ready:
    // bonus_priority_queue();
    
    return 0;
}
