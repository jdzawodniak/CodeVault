#include <Arduino.h>
//https://sensorkit.en.joy-it.net/index.php?title=KY-024_Linear_magnetic_Hall_Sensor#Code_example_Arduino 
// Declaration and initialization of the input pin

int Analog_Pin = A0; // X-axis-signal
int Digital_Pin = 3; // Button

  
void setup ()
{
  pinMode (Analog_Pin, INPUT);
  pinMode (Digital_Pin, INPUT);
       
  Serial.begin (9600); // Serielle output with 9600 bps
}
  
// The program reads the current value of the input pins
// and output it via serial out
void loop ()
{
  float Analog;
  int Digital;
    
  // Current value will be read and converted to the voltage
  Analog = analogRead (Analog_Pin) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Pin);
    
  // and outputted here
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  Serial.print ("Extreme value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not reached yet");
  }
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}