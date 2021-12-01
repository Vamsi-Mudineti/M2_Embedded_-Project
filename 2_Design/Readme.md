The AVR UART is a very powerful and useful peripheral and used in most projects. It can be used for debugging code, user interaction, or just sending data for logging it on a PC. Here's an image of how it basically is built up (based on the ATMega32 UART):

### Flow Chart 

![Flow chart](https://lh3.googleusercontent.com/proxy/OlnRXVORJJqaHgYtP0K7r8Akbx5J-ATCQ6I_wUgWn74PuykDLPmiSOiOY3lsYmCJYAWbTHWI1RbJp8q_DnzkZ9pfxT10YcSYKMUAnLBNhXygRQ)

This clock is used by the Data Recovery Logic: It samples the data and therefore filters it a bit, so that less errors occur. In the middle of a bit that is to be received, it takes three samples: The two (or three) equal samples are high, the bit shifted into the Rx Shift register is high as well. If two samples are wrong, the data in the shift register is also wrong, but that is only possible if the connection is really bad.

The Clock used for shifting in the data is then divided by 16 (see diagram) and therefore corresponds to the baud rate.

As there's no need to sample data for the Tx shift register, it is directly clocked by the baud rate.

The formlua for calculating the Baud rate generated from a specific value in UBRR (UART Baud Rate Register) the AVR datasheets presents this formula:

BAUD= fck / (16(UBRR+1))

Example: System Clock is 8 MHz and we need 9600 Baud. Unfortunatley, the formula above does not give us the UBRR value from fck and baud rate, but Baud rate from fck and UBRR. The better version for this of the formula is:

UBRR =	
fck
- 1
(16 * baud)
Using the value above (8 MHz and 9600 baud) we get the value of 51.08333333 for UBRR. So it's 51. The error we get is the actual baud ratedivided by the desired bud rate: The actual baud rate is (first formula!) 9615 baud, dividing this by 9600 gives 1.0016 and therefore an error of 0.16%.

This will work, but it's not perfect. That's why you can get crystals with funny frequencies, such as 7.3728 MHz: Using that one for 9600 baud gives (2nd formula) us UBRR = 47 and no error. You can find tables with various clock/baud combinations in the AVR datasheets. If you can't find the one you want to use, just use the formulas above which wil give you the same results.

The UART Transmitter

![](http://www.avrbeginners.net/architecture/img/uart_txint.gif)


### Block Diagram

![Image](https://1.bp.blogspot.com/-tD9KEjx6MRU/WaugrgpHpCI/AAAAAAAAAuY/NdZNcdI2RlArvpBodq6v9IfaMOGXS6oXACKgBGAs/w1200-h630-p-k-no-nu/uart_comm_system.png)
