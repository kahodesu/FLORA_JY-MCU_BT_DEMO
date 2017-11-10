////////////////////////////////////////////////////
////////////////////////////////////////////////////
// Code used in Costumes as Game Controllers Class//
////////////// Using Adafruit's FLORA //////////////
////////////// And JY-MCU BT Component /////////////
/////Mod of example from SoftwareSerial Library/////
////////////////////////////////////////////////////
////////////////////////////////////////////////////


#include <SoftwareSerial.h>
// software serial #1: RX = digital pin 10, TX = digital pin 9
SoftwareSerial btPort(10, 9);

char val; // Data received from the serial port
int ledPin = 7; // Onboard LED pin on FLORA is 7

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  btPort.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  while (btPort.available()) { // If data is available to read,
    val = btPort.read(); // read it and store it in val
  }
  
  if (val == 'H') { // If H was received
    digitalWrite(ledPin, HIGH); // turn the LED on
  } 
  
  else {
    digitalWrite(ledPin, LOW); // Otherwise turn it OFF
  }
  delay(100); // Wait 100 milliseconds for next reading
}


