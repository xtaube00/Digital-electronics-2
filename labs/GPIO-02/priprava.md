1. Fill in the following table and enter the number of bits and numeric range for the selected data types defined by C.

    | **Data type** | **Number of bits** | **Range** | **Description** |
   | :-: | :-: | :-: | :-- |
   | `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
   | `int8_t`   | 8 | -128 to +127 | Signed 8-bit integer (char) |
   | `uint16_t` | 16 | 0 to 65 535 | Unsigned 16-bit integer |
   | `int16_t`  | 16 | −32 768 to +32 767 | Signed  16-bit integer |
   | `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
   | `void`     | 0 | 0 | "No return value" |

1. Copy/paste [your solution](https://raw.githubusercontent.com/tomas-fryza/digital-electronics-2/master/solutions/lab1-blink_arduino/src/main.c) with two LEDs from Lab1 to `LAB2-GPIO_LIBRARY > src > main.c` source file. Compile (build) the project and note its size in bytes.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style |  |
   | Registers |  |
   | Library functions |  |

2. Use the datasheet to find out the meaning of the DDRB and PORTB control register values and their combinations. (Let PUD (Pull-up Disable) bit in MCUCR (MCU Control Register) is 0 by default.)

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state, high-impedance |
   | 0 | 1 | | | |
   | 1 | 0 | | | |
   | 1 | 1 | | | |
