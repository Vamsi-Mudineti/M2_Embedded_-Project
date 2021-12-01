The AVR UART is a very powerful and useful peripheral and used in most projects. It can be used for debugging code, user interaction, or just sending data for logging it on a PC. Here's an image of how it basically is built up (based on the ATMega32 UART):

### Flow Chart 

![Flow chart](https://lh3.googleusercontent.com/proxy/OlnRXVORJJqaHgYtP0K7r8Akbx5J-ATCQ6I_wUgWn74PuykDLPmiSOiOY3lsYmCJYAWbTHWI1RbJp8q_DnzkZ9pfxT10YcSYKMUAnLBNhXygRQ)

The Clock used for shifting in the data is then divided by 16 (see diagram) and therefore corresponds to the baud rate. As there's no need to sample data for the Tx shift register, it is directly clocked by the baud rate.

The formlua for calculating the Baud rate generated from a specific value in UBRR (UART Baud Rate Register) the AVR datasheets presents this formula:

                                           BAUD= fck / (16(UBRR+1))

Example: System Clock is 8 MHz and we need 9600 Baud. Unfortunatley, the formula above does not give us the UBRR value from fck and baud rate, but Baud rate from fck and UBRR. The better version for this of the formula is:
                                              UBRR =(	fck/(16 * baud)  -1)

#### The UART Transmitter

![](http://www.avrbeginners.net/architecture/img/uart_tx.gif)

When a byte is transferred to the TX shift register, the UDRE flag is set. The UDRE ISR can write the next byte to UDR without corrupting the transmission in progress.
When a byte is completely shifted out AND no data has been written to UDR by the UDRE ISR, the TXC flag is set.
How the transmitter interrupt flags work together can be understood quite easily with the following flow chart:

![](http://www.avrbeginners.net/architecture/img/uart_txint.gif)

#### The UART Receiver

![](http://www.avrbeginners.net/architecture/img/uart_rx.gif)

The UART receiver is basically built up like the transmitter, but with the appropriate extras for receiving data: Data recovery logic for sampling the data and just one interrupt for the completion of data reception. It uses the same baud rate setting as the transmitter. The data is sampled in the middle of the bit to be received:

### Block Diagram

![Image](https://1.bp.blogspot.com/-tD9KEjx6MRU/WaugrgpHpCI/AAAAAAAAAuY/NdZNcdI2RlArvpBodq6v9IfaMOGXS6oXACKgBGAs/w1200-h630-p-k-no-nu/uart_comm_system.png)
