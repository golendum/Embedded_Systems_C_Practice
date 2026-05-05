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
void can_buffer_init(CANRxBuffer *buf);
uint8_t can_buffer_push(CANRxBuffer *buf, CANMessage *msg);
uint8_t can_buffer_pop(CANRxBuffer *buf, CANMessage *msg);
uint8_t can_buffer_is_empty(CANRxBuffer *buf);
uint8_t can_buffer_is_full(CANRxBuffer *buf);
void can_print_message(CANMessage *msg);


// TODO: Implement can_buffer_init()
void can_buffer_init(CANRxBuffer *buf) {
    // Initialize buffer (set head, tail, count to 0)
    memset(buf -> buffer, 0, sizeof(buf -> buffer));
    buf -> head = 0;
    buf -> tail = 0;
    buf -> count = 0;
}

// TODO: Implement can_buffer_push()
// Add a message to the buffer
uint8_t can_buffer_push(CANRxBuffer *buf, CANMessage *msg) {
    // If buffer is full, return 0 (failure)
    if (can_buffer_is_full(buf)) { return 0; }
    // Otherwise, add message at head position, increment head and count
    // Handle wrap-around when head reaches buffer size
    else {
        buf -> buffer[buf -> head] = *msg;

        buf -> head++;
        buf -> count++;
        if (buf -> head == CAN_RX_BUFFER_SIZE) {
            buf -> head = 0;
        }
    }
    return 1;
}

// TODO: Implement can_buffer_pop()
// Remove and return a message from the buffer
uint8_t can_buffer_pop(CANRxBuffer *buf, CANMessage *msg) {
    // If buffer is empty, return 0 (failure)
    if (can_buffer_is_empty(buf)) { return 0; }
    // Otherwise, get message from tail position, increment tail and decrement count
    // Handle wrap-around when tail reaches buffer size
    else {
        *msg = buf -> buffer[buf -> tail];
        can_print_message(msg);

        buf -> tail++;
        buf -> count--;
        if (buf -> tail == CAN_RX_BUFFER_SIZE) {
            buf -> tail = 0;
        }
    }
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
void can_create_message(CANMessage *msg, uint32_t id, uint8_t dlc, const uint8_t *data, uint32_t timestamp) {
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
void can_register_handler(CANFilterList *filters, uint32_t can_id, CANMessageHandler handler) {
    // Add a new filter to the list
    // If filter list is full, print error

    if (filters -> filter_count >= MAX_FILTERS) {
        printf("Error: filter list is full!\n");
        return;
    }

    filters -> filters[filters -> filter_count].can_id = can_id;
    filters -> filters[filters -> filter_count].handler = handler;
    filters -> filter_count++;

}

// TODO: Implement can_dispatch_message()
// Find and call the handler for a message
void can_dispatch_message(CANFilterList *filters, CANMessage *msg) {
    // Loop through filters and find matching CAN ID
    // If found, call the handler
    // Otherwise, print "No handler for this message"

    for (int i = 0; i < filters -> filter_count; i++) {
        if (filters -> filters[i].can_id == msg -> can_id) {
            filters -> filters[i].handler(msg);
            return;
        }
    }
    printf("No handler found for this message.\n");
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
    can_buffer_init(&rx_buffer);
    // TODO: Initialize filters
    filters.filter_count = 0;
    // TODO: Register message handlers for engine, wheels, and battery
    can_register_handler(&filters, CAN_PRIORITY_HIGH, handle_engine_status);
    can_register_handler(&filters, CAN_PRIORITY_MED, handle_wheel_speed);
    can_register_handler(&filters, CAN_PRIORITY_LOW, handle_battery_status);
    
    // 2. Simulate receiving CAN messages
    printf("\nStep 2: Simulate receiving CAN messages\n");
    
    uint8_t engine_data[] = {0x12, 0x34, 0x55};  // RPM: 4660, Temp: 85°C
    uint8_t wheel_data[] = {0x00, 0x50, 0x00, 0x48};  // Front: 80, Rear: 72
    uint8_t battery_data[] = {0x0D, 0x80, 0x05, 0x00};  // 13.8V, 1280mA
    
    // TODO: Create CAN messages
    CANMessage engine_msg, wheel_msg, battery_msg;
    can_create_message(&engine_msg, CAN_PRIORITY_HIGH, 3, engine_data, 0);
    can_create_message(&wheel_msg, CAN_PRIORITY_MED, 4, wheel_data, 1);
    can_create_message(&battery_msg, CAN_PRIORITY_LOW, 4, battery_data, 2);
    
    // TODO: Push messages to RX buffer
    can_buffer_push(&rx_buffer, &engine_msg);
    can_buffer_push(&rx_buffer, &wheel_msg);
    can_buffer_push(&rx_buffer, &battery_msg);
    // TODO: Pop messages from buffer and dispatch to handlers
    can_buffer_pop(&rx_buffer, &engine_msg);
    can_dispatch_message(&filters, &engine_msg);
    can_buffer_pop(&rx_buffer, &wheel_msg);
    can_dispatch_message(&filters, &wheel_msg);
    can_buffer_pop(&rx_buffer, &battery_msg);
    can_dispatch_message(&filters, &battery_msg);

    // 3. Test buffer full condition
    printf("\nStep 3: Test buffer overflow\n");
    // TODO: Fill buffer to capacity
    CANMessage filler_msgs[CAN_RX_BUFFER_SIZE];

    for (int i = 0; i < CAN_RX_BUFFER_SIZE; i++) {
        uint8_t filler_data[] = {(uint8_t)i};
        can_create_message(&filler_msgs[i], 0x400 + i, 1, filler_data, i);
        can_buffer_push(&rx_buffer, &filler_msgs[i]);
    }

    printf("Buffer filled to capacity (%d messages)\n", CAN_RX_BUFFER_SIZE);

    // TODO: Try to add one more message
    uint8_t overflow_data[] = {0xFF};

    CANMessage overflow_msg;
    can_create_message(&overflow_msg, 0x500, 1, overflow_data, 100);

    can_buffer_push(&rx_buffer, &overflow_msg);

    printf("\n");
}

// ============ BONUS: Message Filtering and Sorting ============

typedef struct {
    uint32_t can_id;
    uint8_t priority;
} CANMessagePriority;

/*
typedef struct {
    uint32_t can_id;          // 11-bit or 29-bit identifier
    uint8_t dlc;              // Data Length Code (0-8)
    uint8_t data[8];          // CAN data bytes
    uint32_t timestamp;       // When message was received
} CANMessage;
*/

// TODO: Implement priority queue insertion
void can_priority_insert(CANMessage *queue[], uint32_t *count, CANMessage *msg, uint32_t priority) {
    // Insert message into queue maintaining priority order
    int insert = 0;
    while ((insert < *count) && (queue[insert] -> can_id < priority)) {
        insert++;
    }

    for (int i = *count; i > insert; i--) {
        queue[i] = queue[i-1];
    }

    queue[insert] = msg;
    (*count)++;
}

void bonus_priority_queue() {
    printf("=== BONUS: CAN Message Priority Queue ===\n\n");
    
    // TODO: Create priority queue and add messages with different priorities
    CANMessage *priority_queue[MAX_FILTERS];
    uint32_t count = 0;

    uint8_t engine_data[] = {0x12, 0x34, 0x55};  // RPM: 4660, Temp: 85°C
    uint8_t wheel_data[] = {0x00, 0x50, 0x00, 0x48};  // Front: 80, Rear: 72
    uint8_t battery_data[] = {0x0D, 0x80, 0x05, 0x00};  // 13.8V, 1280mA
    
    // TODO: Create CAN messages
    CANMessage engine_msg, wheel_msg, battery_msg;
    can_create_message(&engine_msg, CAN_PRIORITY_HIGH, 3, engine_data, 0);
    can_create_message(&wheel_msg, CAN_PRIORITY_MED, 4, wheel_data, 1);
    can_create_message(&battery_msg, CAN_PRIORITY_LOW, 4, battery_data, 2);

    can_priority_insert(priority_queue, &count, &battery_msg, CAN_PRIORITY_LOW);
    can_priority_insert(priority_queue, &count, &engine_msg, CAN_PRIORITY_HIGH);
    can_priority_insert(priority_queue, &count, &wheel_msg, CAN_PRIORITY_MED);

    // Print sorted queue
    printf("Priority Queue (sorted by priority):\n");
    for (uint32_t i = 0; i < count; i++) {
        printf("  %d. CAN ID: 0x%03X (Priority: 0x%X)\n", i+1, priority_queue[i]->can_id, priority_queue[i]->can_id);
    }
}

int main() {
    project_2_can_bus();
    
    // Uncomment when ready:
    bonus_priority_queue();
    
    return 0;
}
