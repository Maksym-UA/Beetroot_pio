#include <Arduino.h>

#define ADC_PIN 4
#define VREF 3.0
#define ADC_RESOLUTION 4095.0
#define LED_PIN 16
#define VOLTAGE_THRESHOLD 1.5
#define VOLTAGE_GIST 2.0

float getVoltage(int adcValue){
  //convert ADC value to voltage on the sensor
  return ((adcValue / ADC_RESOLUTION) * VREF);
}


void setup(){
  //start the serial monitor at baude rate of 115200
  Serial.begin(115200);
  pinMode (LED_PIN, OUTPUT); //init pin 16 as output
  analogReadResolution(12); //set the ADC resolution to 12 bits (0-4095)
  Serial.println("Setup is ready!");

}


void loop(){
  int adcValue = 0;
  adcValue = analogRead(ADC_PIN); //read the ADC value on the pin
  float voltage = getVoltage(adcValue); //convert ADC value to voltage
  uint32_t millivolts = analogReadMilliVolts(4); //read the voltage in millivolts
  float error = (1 - ((voltage * 1000) / millivolts)) * 100;

  
  Serial.printf(
    "ADC value: %d, Voltage %.2f V, Millivolts %u mV----Measurement Error: %.2f%%----\n",  
    adcValue, voltage, millivolts, error);


  if (voltage < VOLTAGE_THRESHOLD ){
    digitalWrite(LED_PIN, HIGH); //turn on the led if the voltage is below the threshold
    Serial.println("The LED is on. Voltage is below threshold.");
  }
  else if (voltage > VOLTAGE_THRESHOLD){
    digitalWrite(LED_PIN, LOW); //turn on the led if the voltage is below the threshold
    Serial.println("The LED is off. Voltage is above threshold.");
  } 

  delay(100);
}