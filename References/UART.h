/*
 * UART.h
 *
 *  Created on: Nov 1, 2022
 *      Author: renzogarzamotta
 */

#ifndef UART_H_
#define UART_H_

#include "msp.h"
#include "system_msp432p401r.h"
#include <stdio.h>
#include <string.h>

#define UART0       0x00
#define UART1       0x01
#define UART2       0x02
#define UART3       0x03

#define UCA0_PORT   P1
#define TX0         BIT3
#define RX0         BIT2
#define UCA0        (TX0|RX0)

#define UCA1_PORT   P2
#define TX1         BIT3
#define RX1         BIT2
#define UCA1        (TX1|RX1)

#define UCA2_PORT   P3
#define TX2         BIT3
#define RX2         BIT3
#define UCA2        (TX2|RX2)

#define UCA3_PORT   P9
#define TX3         BIT7
#define RX3         BIT6
#define UCA3        (TX3|RX3)

#define SYS_CLK     48000000
#define BAUD_RATE   9600

//void uartInit(uint8_t uartMod, uint32_t baudRate, uint8_t parity, uint8_t firstBitSel, uint8_t charLen, uint8_t stopBit, uint8_t interrupt);
//void setparity(uint8_t parity);
//void setFirstBitSel(uint8_t firstBitSel);
//void setCharLen(uint8_t charLen);
//void setStopBit(uint8_t stopBit);
//
//void setBaudRate(uint32_t baudRate);
//void setInt(uint8_t interrupt);
//void initInt(void);

void initGPIO(void);
void UART1_init(void);
void uartInitRX(void);
int UART1_charOut(char data);
int UART1_strOut(char* data);
void UART1_strIn(char* data);
char UART1_charIn(void);
//void charSend2(uint8_t data);
//void strSend2(char* data);
//void strRec2(char* data);

void UART0_init(void);
int UART0_Send(char data);
int UART0_MSend(char* data);
char UART0_receive(void);

#endif /* UART_H_ */
