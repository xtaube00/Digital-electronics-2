# Lab 8: INSERT_YOUR_FIRSTNAME INSERT_YOUR_LASTNAME

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-: | :-: |
   | `add r24, r0` | `0000_1101_1000_0000` | `0d f0`  |  |
   | `com r26` | `1001_0101_1010_1000` | `` |  |
   | `eor r26, r27` | `0010_0111_1010_0011` |  |  |
   | `mul r22, r20` | `0010_0111_0110_0100`  | `64 9f` |  |
   | `ret` | `1001_0101_0000_1000` | `95 08` |  |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 1 7 13 6 9 5 4 0 3 14 11 12 2 10 8 | 15 |
   | 4, 2 |  |  |
   | 4, 1 | 1 5 4 3 13 7 12 0 2 10 9 6 11 14 8 | 15 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()