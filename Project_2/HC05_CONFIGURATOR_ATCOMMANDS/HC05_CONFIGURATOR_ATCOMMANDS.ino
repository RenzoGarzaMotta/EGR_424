// #include <SoftwareSerial.h>

// SoftwareSerial BTSerial(10, 11);   // RX | TX

// void setup() {
//   pinMode(9, OUTPUT);    /* this pin will pull the HC-05 pin 34 (KEY pin) HIGH to switch module to AT mode */
//   digitalWrite(9, HIGH); 
  
//   Serial.begin(38400);
//   Serial.println("Enter AT Commands:");
//   BTSerial.begin(38400);  // HC-05 default speed in AT command mode
// }

// void loop() {

// //The code below allows for commands and messages to be sent from COMPUTER (serial monitor) -> HC-05
//   if (Serial.available())           // Keep reading from Arduino Serial Monitor 
//     BTSerial.write(Serial.read());  // and send to HC-05

// //The code below allows for commands and messages to be sent from HC-05 -> COMPUTER (serial monitor)    
//   if (BTSerial.available())         // Keep reading from HC-05 and send to Arduino 
//     Serial.write(BTSerial.read());  // Serial Monitor
// }


// /*  Simple program to exercise the HC-05 zs-40 Bluetooth module by pairing with a PC
 
// Uses hardware serial to talk to the host computer and software serial for 
// communication with the Bluetooth module
 
// Connections
//   Arduino 5V to module VCC
//   Arduino GND to module GND
//   Arduino D9 to module RX using a voltage divider
//   Arduino D8 to module TX

//   When a command is entered in the serial monitor on the computer 
//   the Arduino will relay it to the bluetooth module and display the result in
//   the Bluetooth terminal window and vice versa.

//   Uses Softserial.h library
// */ 
// #include <SoftwareSerial.h>
// SoftwareSerial SoftSerial(10, 11); // RX | TX pins.  Can be reassigned to other pins if needed
 
// const long BAUDRATE = 9600;    // This is the default communication baud rate of the HC-05 module
// char c = ' ';                  // Character being transmitted 
// boolean NL = true;             // Newline.  True indicates we should show a '>'
// //===============================================================================
// //  Initialization
// //===============================================================================
// void setup() 
// {
//     SoftSerial.begin(BAUDRATE);  // Init soft serial object
//     Serial.begin(9600);          // Init hardware serial
//     Serial.println("Test started - Enter something to send to computer or Android phone");
//     SoftSerial.println("Test started - Enter something to send to Serial Monitor Window");
// }
// //===============================================================================
// //  Main
// //=============================================================================== 
// void loop()
// {
//      // Read from the Bluetooth module and send to the Arduino Serial Monitor
//     if (SoftSerial.available())
//     {
//         c = SoftSerial.read();
//         Serial.write(c);
//     }
//      // Read from the Serial Monitor and send to the Bluetooth module
//     if (Serial.available())
//     {
//         c = Serial.read();
//         SoftSerial.write(c);   
 
//         // Echo the user input to the main window. The ">" character indicates the user entered text.
//         if (NL) { Serial.print(">");  NL = false; }
//         Serial.write(c);
//         if (c==10) NL = true;    // char '10' is the newline character
//     }
 
// }

//  Sketc: basicSerialWithNL_001
// 
//  Uses hardware serial to talk to the host computer and software serial 
//  for communication with the Bluetooth module
//  Intended for Bluetooth devices that require line end characters "\r\n"
//
//  Pins
//  Arduino 5V out TO BT VCC
//  Arduino GND to BT GND
//  Arduino D9 to BT RX through a voltage divider
//  Arduino D8 BT TX (no need voltage divider)
//
//  When a command is entered in the serial monitor on the computer 
//  the Arduino will relay it to the bluetooth module and display the result.
//
 
