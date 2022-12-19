# Project 2

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

## Recommended GitHub repository structure

   ```c
   Projek2        // PlatfomIO project
   +¦¦ include         // Included files
   +¦¦ lib             // Libraries
   +¦¦ src             // Source file(s)
   -   L¦¦ main.c
   +¦¦ test            
   +¦¦ platformio.ini  // Project Configuration File
   L¦¦ README.md       // Report of this project
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
