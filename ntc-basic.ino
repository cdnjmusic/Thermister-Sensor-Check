/**
  Basic NTC Thermistor demo
  https://wokwi.com/arduino/projects/299330254810382858

  Assumes a 10K@25℃ NTC thermistor connected in series with a 10K resistor.

  Copyright (C) 2021, Uri Shaked
*/

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");

  if (celsius < 30) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    Serial.println("Green LED on");
  } else if (celsius >= 30 && celsius <= 80) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    Serial.println("Yellow LED on");
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    Serial.println("Red LED on");
  }
  
  delay(1000);
}
