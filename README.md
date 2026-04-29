# Embedded C Practice Problems & Projects
This folder contains structured practice problems for embedded C development, specifically tailored for automotive embedded systems work.

## File Organization

### Exercises (Basic to Intermediate)
1. **01_basics.c** - Data types, I/O, basic operators
2. **02_bit_manipulation.c** - Bitwise operations, bit flags, register patterns ⭐ CRITICAL for embedded
3. **03_pointers.c** - Pointers, memory, dereferencing
4. **04_structs.c** - Structs, bit fields, memory layout
5. **05_functions_statemachines.c** - Functions, callbacks, state machines

### Embedded Projects (Application-Level)
1. **01_gpio_control.c** - GPIO pins, interrupt handling, register access
2. **02_can_bus.c** - CAN protocol, message queues, callbacks (AUTOMOTIVE!)

## How to Use These Problems

Each file contains multiple problems/projects with TODO comments. Follow these steps:

### For Exercise Files:
1. Open the file
2. Read the problem descriptions
3. Implement the TODO sections
4. Compile: `gcc -Wall -std=c11 -g -o output.exe filename.c`
5. Run: `./output.exe`

### For Project Files:
1. These are more complex, real-world scenarios
2. Implement all required functions
3. Complete the main project execution
4. Try the bonus challenges

## Compilation Examples

```powershell
# Basic compilation
gcc -o 01_basics.exe 01_basics.c
./01_basics.exe

# With all warnings and debugging
gcc -Wall -std=c11 -g -o 02_bits.exe 02_bit_manipulation.c
./02_bits.exe

# Compile all files
gcc -Wall -std=c11 -o all_exercises.exe 0*.c
```

## Learning Path Recommended

1. **Start here:** 01_basics.c
   - Get comfortable with printf/scanf
   - Understand data types

2. **Then:** 02_bit_manipulation.c ⭐⭐⭐
   - This is ESSENTIAL for embedded systems
   - Register access, GPIO control, hardware configuration
   - Spend extra time here!

3. **Next:** 03_pointers.c
   - Understand memory, hardware register access
   - Function pointers and callbacks

4. **Then:** 04_structs.c
   - Organize your code
   - Register definitions

5. **Intermediate:** 05_functions_statemachines.c
   - State machines are everywhere in embedded systems
   - Callback systems for event handling

6. **Projects:** Start with GPIO control
   - Apply everything you learned
   - Simulate real hardware

## Key Topics for Automotive Embedded Systems

### High Priority (Must Know)
- ✅ Bit manipulation (GPIO, registers)
- ✅ Structs and bit fields (register maps)
- ✅ Pointers (register access, DMA)
- ✅ State machines (CAN, diagnostics)
- ✅ Interrupts and callbacks

### Medium Priority
- ⚠️  Circular buffers (CAN/UART RX buffers)
- ⚠️  Function pointers and callbacks
- ⚠️  Memory layout and alignment

### Nice to Have
- 📚 Compilation flags and optimization
- 📚 Debugging techniques
- 📚 Code organization patterns

## Automotive Systems Concepts

### CAN Bus (Controller Area Network)
- See: 02_can_bus.c
- Message format, IDs, priority handling
- Used in every modern vehicle!

### GPIO (General Purpose Input/Output)
- See: 01_gpio_control.c
- Digital I/O control
- Interrupt handling

### Register Access Patterns
- See: throughout all files
- Memory-mapped peripherals
- Bit fields vs bit manipulation

## Tips for Success

1. **Don't skip bit manipulation** - This is the foundation of embedded systems
2. **Test incrementally** - Compile and run after each function
3. **Print debug info** - Use printf liberally while learning
4. **Understand memory** - Use sizeof() and offsetof() to understand layout
5. **Read actual datasheets** - Reading STM32/MPC datasheets daily

## Troubleshooting

### Compilation Errors
```
error: undeclared identifier
→ Check if variable is initialized before use

error: invalid initializer
→ Check struct member types match expected values

undefined reference to...
→ Make sure all functions are implemented, not just declared
```

### Runtime Issues
```
Segmentation fault
→ Check pointer dereferences, buffer bounds

Program hangs
→ Check for infinite loops, missing break statements
```

## Next Steps After These Exercises

1. Study microcontroller datasheets (STM32, PIC, etc.)
2. Learn about UART/SPI/I2C communication
3. Study real CAN network protocols
4. Explore FreeRTOS for multitasking
5. Practice with actual development boards if possible

## Resources

- CAN Protocol: ISO 11898
- GCC Compiler Manual: https://gcc.gnu.org/
- Embedded C Best Practices: "Embedded C" by Michael Barr
- ARM Cortex-M MCU Documentation (if working with STM32)
