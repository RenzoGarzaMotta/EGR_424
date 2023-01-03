#include "UART.h"

char tx1_data [99];
char rx1_data [99];
char tx2_data [99];
char rx2_data [99];
char str[10];
int s = 0;
int r = 0;

//void uartInit(uint8_t uartModule, uint32_t baudRate, uint8_t parity, uint8_t firstBitSel, uint8_t charLen, uint8_t stopBit, uint8_t interrupt){
//    switch(uartModule){
//        case UART0:
//            enUART = EUSCI_A0;
//            enUART->CTLW0 |= EUSCI_A_CTLW0_SWRST;
//            enUART->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
//            setparity(parity);
//            setFirstBitSel(firstBitSel);
//            setCharLen(charLen);
//            setStopBit(stopBit);
//
//            setBaudRate(baudRate);
//
//            EUSCI_A0->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;
//
//            setInt(interrupt);
//            initInt(void);
//            break;
//        case UART1:
//            break;
//        case UART2:
//            break;
//        case UART3:
//            break;
//        default:
//            break;
//    }
//}
//
//void setparity(uint8_t parity){
//
//}
//
//void setFirstBitSel(uint8_t firstBitSel);
//void setCharLen(uint8_t charLen);
//void setStopBit(uint8_t stopBit);
//
//void setBaudRate(uint32_t , uint32_t baudRate){
//    switch(baudRate){
//        case 110:
//            //Disable Oversampling Mode
//            EUSCI_A0->MCTLW &=~ (EUSCI_A_MCTLW_OS16);
//            //UCBRx = 78
//            EUSCI_A0->BRW = 312;
//            break;
//        case 300:
//            break;
//        case 600:
//            break;
//        case 1200:
//            break;
//        case 2400:
//            break;
//        case 4800:
//            break;
//        case 9600:
//            break;
//        case 14400:
//            break;
//        case 19200:
//            break;
//        case 38400:
//            break;
//        case 57600:
//            break;
//        case 115200:
//            break;
//        case 128000:
//            break;
//        case 256000:
//            break;
//        default:
//            break;
//    }
//}
//void setInt(uint8_t interrupt);
//void initInt(void);


void UART1_init(void){

//    //BAUD RATE 115200 SETTINGS
//
//    EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SWRST;
//    EUSCI_A1->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
//    EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;   //Select SMCLK for BRCLK
//
//    //BRCLK = 12MHz
//    //Baud Rate = 115200
//    //USCOS16 = 1
//    //UCBRFx = 8
//    //UCBRSx = 0x20
//    EUSCI_A1->MCTLW |= (0x2000|0x0080|EUSCI_A_MCTLW_OS16);
//    //UCBRx = 6
//    EUSCI_A1->BRW = 6;
//
//    EUSCI_A1->MCTLW &=~ EUSCI_A_MCTLW_BRS_MASK;
//
//
//    EUSCI_A1->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;
//
//    EUSCI_A1->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);
//
//    NVIC->ISER[0] = 1 << ((EUSCIA1_IRQn) & 31);   //Enable Watchdog interrupt

//    //BAUD RATE 9600 SETTINGS
//
//    EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SWRST;
//    EUSCI_A1->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
//    EUSCI_A1->CTLW0 |= (EUSCI_A_CTLW0_SSEL__SMCLK);   //Select SMCLK for BRCLK
//
//    //BRCLK = 12MHz
//    //Baud Rate = 9600
//    //USCOS16 = 1
//    //UCBRFx = 2
//    EUSCI_A1->MCTLW |= (0x0020|EUSCI_A_MCTLW_OS16);
//    //UCBRx = 78
//    EUSCI_A1->BRW = 78;
//    //UCBRSx = 0x0
//    EUSCI_A1->MCTLW &=~ EUSCI_A_MCTLW_BRS_MASK;
//
//    //Select Alternate functions for UART0 pins.
//    UCA1_PORT->SEL0 |= UCA1;
//    UCA1_PORT->SEL1 &=~ UCA1;
//
//    EUSCI_A1->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;
//
//    EUSCI_A1->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);
//
//    NVIC->ISER[0] = 1 << ((EUSCIA1_IRQn) & 31);   //Enable Watchdog interrupt

    //BAUD RATE 9600 SETTINGS SIMPLE

    //Disable the UART by enabling the software RESET
    EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SWRST;

    //Disable Oversampling Mode
    EUSCI_A1->MCTLW &=~ (EUSCI_A_MCTLW_OS16);
    //UCBRx = 78
    EUSCI_A1->BRW = 5000;//312 @ 3MHz, 5000 @48MHz
    //EUSCI_A1->BRW = SYS_CLK/BAUD_RATE;

    //Configure Control Register
    //No Parity
    //LSB First
    //8bit Data
    //One Stop Bit
    //UART Mode
    //Asynchronous Mode
    //SMCLK
    EUSCI_A1->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
    EUSCI_A1->CTLW0 |= (EUSCI_A_CTLW0_SSEL__SMCLK);   //Select SMCLK for BRCLK

    //Select Alternate functions for UART0 pins.
    UCA1_PORT->SEL0 |= UCA1;
    UCA1_PORT->SEL1 &=~ UCA1;

    //Enable the UART by disabling the software RESET
    EUSCI_A1->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;

    EUSCI_A1->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);

    NVIC->ISER[0] = 1 << ((EUSCIA1_IRQn) & 31);   //Enable Watchdog interrupt
}

int UART1_strOut(char* data){
    unsigned int len = strlen(data);
    while(*data != '\0'){
        while(EUSCI_A1->STATW & EUSCI_A_STATW_BUSY);
        EUSCI_A1->TXBUF = *data++;
        //Insert Delay
        __delay_cycles(48000*5);
    }
    return len;
}

int UART1_charOut(char data){
    while(EUSCI_A1->STATW & EUSCI_A_STATW_BUSY);
    EUSCI_A1->TXBUF = data;
    __delay_cycles(48000*5);
    return (int) data;
}

void UART1_strIn(char* data){
    char temp;

    temp = UART1_charIn();
//    if((data[r - 1] != '\x0D') && (temp != '\x0A')){
    if(temp != '\x0A'){
        data[r] = temp;
        r++;
    }else{
        data[r] = temp;
        r = 0;
    }
}

char UART1_charIn(void){
    while(EUSCI_A1->STATW & EUSCI_A_STATW_BUSY);
    return EUSCI_A1->RXBUF;
    __delay_cycles(48000*3);
}

////------------UART_InString------------
//// Accepts ASCII characters from the serial port
////    and adds them to a string until <enter> is typed
////    or until max length of the string is reached.
//// It echoes each character as it is inputed.
//// If a backspace is inputed, the string is modified
////    and the backspace is echoed
//// terminates the string with a null character
//// uses busy-waiting synchronization on RDRF
//// Input: pointer to empty buffer, size of buffer
//// Output: Null terminated string
//// -- Modified by Agustinus Darmawan + Mingjie Qiu --
//void UART_InString(char *bufPt, uint16_t max) {
//int length=0;
//char character;
//  character = UART_InChar();
//  while(character != CR){
//    if(character == BS){
//      if(length){
//        bufPt--;
//        length--;
//        UART_OutChar(BS);
//      }
//    }
//    else if(length < max){
//      *bufPt = character;
//      bufPt++;
//      length++;
//      UART_OutChar(character);
//    }
//    character = UART_InChar();
//  }
//  *bufPt = 0;
//}

//void strSend2(char* data){
////    if(s <= sizeof(data)){
////        charSend(data[s]);
////        s++;
////    }
//    for(s = 0; s <= strlen(data); s++){
//        charSend2(data[s]);
//    }
//    s = 0;
//}
//
//void charSend2(uint8_t data){
//    while(EUSCI_A2->STATW & EUSCI_A_STATW_BUSY);
//    EUSCI_A2->TXBUF = data;
//}
//
//void strRec2(char* data){
//    char temp;
////    while(EUSCI_A2->STATW & EUSCI_A_STATW_BUSY);
//    while((EUSCI_A2->IFG & EUSCI_A_IFG_RXIFG) == 0);
//    temp = EUSCI_A2->RXBUF;
//    if(temp != '\x00'){
//        data[r] = temp;
//        r++;
//    }else{
//        r = 0;
//    }
//}

void UART0_init(void){
    //BAUD RATE 9600 SETTINGS

    //Disable the UART by enabling the software RESET
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST;

    //Disable Oversampling Mode
    EUSCI_A0->MCTLW &=~ (EUSCI_A_MCTLW_OS16);
    //UCBRx = 78
    EUSCI_A0->BRW = 312;

    //Configure Control Register
    //No Parity
    //LSB First
    //8bit Data
    //One Stop Bit
    //UART Mode
    //Asynchronous Mode
    //SMCLK
    EUSCI_A0->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
    EUSCI_A0->CTLW0 |= (EUSCI_A_CTLW0_SSEL__SMCLK);   //Select SMCLK for BRCLK

    //Select Alternate functions for UART0 pins.
    UCA0_PORT->SEL0 |= UCA0;
    UCA0_PORT->SEL1 &=~ UCA0;

    //Enable the UART by disabling the software RESET
    EUSCI_A0->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;

    //EUSCI_A0->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);

    NVIC->ISER[0] = 1 << ((EUSCIA0_IRQn) & 31);   //Enable Watchdog interrupt
}

int UART0_Send(char data){
    while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
    EUSCI_A0->TXBUF = data;
    //Insert Delay
    __delay_cycles(48000*2);
    return (int)data;
}

int UART0_MSend(char* data){
    unsigned int len = strlen(data);

    while(*data != '\0'){
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
        EUSCI_A0->TXBUF = *data++;
        //Insert Delay
        __delay_cycles(48000*2);
    }
    return len;
}

char UART0_receive(void){
    while((EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG) == 0);
    return EUSCI_A0->RXBUF;
}

void UART2_init(void){
//    //BAUD RATE 115200 SETTINGS
//
//    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SWRST;
//    EUSCI_A2->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
//    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;   //Select SMCLK for BRCLK
//
//    //BRCLK = 12MHz
//    //Baud Rate = 115200
//    //USCOS16 = 1
//    //UCBRFx = 8
//    //UCBRSx = 0x20
//    EUSCI_A2->MCTLW |= (0x2000|0x0080|EUSCI_A_MCTLW_OS16);
//    //UCBRx = 6
//    EUSCI_A2->BRW = 6;
//
//    EUSCI_A2->MCTLW &=~ EUSCI_A_MCTLW_BRS_MASK;
//
//
//    EUSCI_A2->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;
//
//    EUSCI_A2->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);
//
//    NVIC->ISER[0] = 1 << ((EUSCIA2_IRQn) & 31);   //Enable Watchdog interrupt

//    //BAUD RATE 9600 SETTINGS
//
//    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SWRST;
//    EUSCI_A2->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
//    EUSCI_A2->CTLW0 |= (EUSCI_A_CTLW0_SSEL__SMCLK);   //Select SMCLK for BRCLK
//
//    //BRCLK = 12MHz
//    //Baud Rate = 9600
//    //USCOS16 = 1
//    //UCBRFx = 2
//    EUSCI_A2->MCTLW |= (0x0020|EUSCI_A_MCTLW_OS16);
//    //UCBRx = 78
//    EUSCI_A2->BRW = 78;
//    //UCBRSx = 0x0
//    EUSCI_A2->MCTLW &=~ EUSCI_A_MCTLW_BRS_MASK;
//
//    //Select Alternate functions for UART0 pins.
//    UCA2_PORT->SEL0 |= UCA2;
//    UCA2_PORT->SEL1 &=~ UCA2;
//
//    EUSCI_A2->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;
//
//    EUSCI_A2->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);
//
//    NVIC->ISER[0] = 1 << ((EUSCIA2_IRQn) & 31);   //Enable Watchdog interrupt

    //BAUD RATE 9600 SETTINGS SIMPLE

    //Disable the UART by enabling the software RESET
    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SWRST;

    //Disable Oversampling Mode
    EUSCI_A2->MCTLW &=~ (EUSCI_A_MCTLW_OS16);
    //UCBRx = 78
    EUSCI_A2->BRW = 312;
    //EUSCI_A2->BRW = SYS_CLK/BAUD_RATE;

    //Configure Control Register
    //No Parity
    //LSB First
    //8bit Data
    //One Stop Bit
    //UART Mode
    //Asynchronous Mode
    //SMCLK
    EUSCI_A2->CTLW0 &=~ 0xFFFE; //Clear all bits except for the reset bit
    EUSCI_A2->CTLW0 |= (EUSCI_A_CTLW0_SSEL__SMCLK);   //Select SMCLK for BRCLK

    //Select Alternate functions for UART0 pins.
    UCA2_PORT->SEL0 |= UCA2;
    UCA2_PORT->SEL1 &=~ UCA2;

    //Enable the UART by disabling the software RESET
    EUSCI_A2->CTLW0 &=~ EUSCI_A_CTLW0_SWRST;

    EUSCI_A2->IE |= (EUSCI_A_IE_TXIE|EUSCI_A_IE_RXIE);

    NVIC->ISER[0] = 1 << ((EUSCIA2_IRQn) & 31);   //Enable Watchdog interrupt
}



//Receiver Interrupt Handler
void EUSCIA2_IRQHandler(void){
    if(EUSCI_A2->IFG & EUSCI_A_IFG_TXIFG){
        EUSCI_A2->IFG &=~ EUSCI_A_IFG_TXIFG;
    }
    if(EUSCI_A2->IFG & EUSCI_A_IFG_RXIFG){
        EUSCI_A2->IFG &=~ EUSCI_A_IFG_RXIFG;
        //strRec2(rx2_data);
    }
}
