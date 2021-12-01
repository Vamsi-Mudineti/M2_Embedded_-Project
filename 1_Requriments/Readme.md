## 1.	Introduction:

    Communication between multiple controllers is almost a must when it comes to large projects.
    So, in this Lab we’ll investigate in brief the use of the atmega328, PIC16F877a 
    and the Arduino Uno in some communication scenarios.
    Also come across a few widely used communication protocols such as I2C, SPI.

## 2.	Objectives

    • Explore the communication between multiple microcontrollers.
    • Use Visual Studio Code.
    • Using Proteus as a simulator for such a communication.
    • Use the Arduino Serial Plotter.

## 3.	Requirements

- Components Required
- Hardware: ATMEGA8 (2 pieces), power supply (5v), AVR-ISP PROGRAMMER, 100uF capacitor (connected across power supply), 1KΩ resistor (two pieces), LED , Button.
- Let us understand the serial communication in AVR microcontrollers. Here ATMEGA sends data to the other ATMEGA in serial. It has other mode of communication but for easy communication we are choosing RS232. The RS232 pin of first ATMEGA8 is connected to RXD pin of second ATMEGA8.

![image](https://user-images.githubusercontent.com/94225184/144241120-0b9c442f-328e-4a43-8b93-0d1c1bcf3db1.png)


The data communication established is programmed to have:

- Eight data bits
- Two stop bits
- No parity check bit
- Baud rate of 2400 BPS(Bits Per Second)
- Asynchronous communication (No clock share between two ATMEGA8)
- So we have two set registers for two ATMEGA8 differently, where one acts as TRANSMITTER and other acts as RECEIVER.

![image](https://user-images.githubusercontent.com/94225184/144240979-2592b0f2-eb1e-4a66-8e82-c5477fe26c03.png)

The communication between two ATMEGA is established as eight bit communication. By matching the communication with table we have, UCSZ0, UCSZ1 to one and UCSZ2 to zero.

We have to set these on both receiving and transmitting side.
DARK GREY (UDRE): (TRASMITTER SIDE) This bit not set during startup but it is used during working to check whether transmitter is ready to transmit or not. See the program on TRASMITTER SIDE for more details.

LIGHT GREY (RXC): (RECEIVING SIDE) This bit not set during startup but it is used during working to check whether receiver is ready to receive data or not. See the program on RECEIVING SIDE for more details.

VOILET (TXEN): (TRASMITTER SIDE) This bit is set for enabling transmitter pin on TRASMITTER SIDE.

RED (RXEN): (RECEIVING SIDE) This bit represents receive data feature, this bit must be set for the data from the module to be received by the controller, it also enables RXD pin of controller.



