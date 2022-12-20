# Project 2

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

## Recommended GitHub repository structure

   ```c
   project_2.0            // PlatfomIO project
   ├── include         
   ├── lib             
   ├── src              // Source file
   │   └── main.c
   ├── test
   │     
   └── platformio.ini   // Project Configuration File
   └── README.md        // Report of this project
   ```

## Recommended README.md file structure

### Team members

* Benjamin Nimmerrichter (responsible for xxx)
* Jakub Tauber (responsible for xxx)

## Hardware 
### Výstupy pro použítí PWM 
![uno](obrazky/uno.png)
### Reálné schéma zapojení
![uno](obrazky/schema.png)

| **Servo motor** | **Popis konektorů** | **Označení** |
| :-: | :-: | :-: |
| PWM | PWM signál | ![uno](obrazky/orn.png) |
| VCC | Napájení (+5V) | ![uno](obrazky/cerv.png) |
| GND | Napájení (zem) | ![uno](obrazky/hne.png) |



## Software description

Pro vytvoření ovládacího signálu pro řízení servo motorů jsme použili registry TCCR1A a TCCR1B v režimu **Fast PWM** 
* TCCR1A – Timer/Counter1 Control Register A:

| **Bit** | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| **(0x80)** | COM1A1 | COM1A0 | COM1B1 | COM1B0 | - | - | WGM11 | WGM10 |
| **Read/Write** | R/W | R/W | R/W | R/W | R | R | R/W | R/W |
| **Value** | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
| **Description** | Compare Outuput Mode for Channel A  | Compare Outuput Mode for Channel A  | Compare Outuput Mode for Channel B | Compare Outuput Mode for Channel B | - | - | Waveform Generation Mode | Waveform Generation Mode |

* Výstupní režim registru TCCR1A (Fast PWM)

| COM1A1/COM1B1 | COM1A0/COM1B0 | Description 
| :-: | :-: | :-: |
| 0 | 0 | Normal port operation, OC1A/OC1B disconnected | 
| 0 | 1 | WGM13:0 = 14 or 15: Toggle OC1A on compare match, OC1B disconnected (normal port operation). For all other WGM1 settings, normal port operation |
| 1 | 0 | Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM (non-inverting mode) | 
| 1 | 1 | Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM (inverting mode) |

* TCCR1B – Timer/Counter1 Control Register B:

| **Bit** | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| **(0x81)** | ICNC1 | ICES1 | - | WGM13 | WGM12 | CS12 | CS11 | CS10 |
| **Read/Write** | R/W | R/W | R | R/W | R/W | R/W | R/W | R/W |
| **Value** | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 |
| **Description** | Input Capture Noise Canceler |  Input Capture Edge Select | Reserved bit | Waveform Generation Mode | Waveform Generation Mode | Clock Select | Clock Select | Clock Select |
## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. [Servo motor](https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/)
