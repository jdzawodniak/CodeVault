#include <Arduino.h>

#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define SwitchPin 2 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 8;

int SentMessage[1] = {000}; 
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(){
  pinMode(led, OUTPUT);   

  Serial.begin (9600);
  pinMode(SwitchPin, INPUT_PULLUP); 
  digitalWrite(SwitchPin,HIGH); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
  Serial.println("Radio On");
}

void loop()
{
  if (digitalRead(SwitchPin) == LOW)    // If switch is pressed
  { 
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  SentMessage[0] = 111;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println("Send pressed data to NRF24L01");
  }
  else 
  {
      digitalWrite(led, LOW); 
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);      // Send idle data to NRF24L01
      Serial.println("Send idle data to NRF24L01");
  }
}