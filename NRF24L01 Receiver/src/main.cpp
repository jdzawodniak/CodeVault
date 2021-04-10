#include <Arduino.h>

#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define LED_PIN 8

int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01
RF24 radioRx(9,10); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{
  Serial.begin(9600);
  radioRx.begin(); // Start the NRF24L01
  
  radioRx.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  
  radioRx.startListening(); // Listen to see if information received
  Serial.println("Radio On");
  
  pinMode(LED_PIN, OUTPUT); 
}

void loop(void)
{
  while (radioRx.available())
  {
    radioRx.read(ReceivedMessage, 1); // Read information from the NRF24L01
    Serial.println("Message Received");

    if (ReceivedMessage[0] == 111) // Indicates switch is pressed
    {
      Serial.println("111-ON");
      digitalWrite(LED_PIN, HIGH);
    }
    else
    {
       Serial.println("000");
       digitalWrite(LED_PIN, LOW);
    }
    delay(2);
   }
}