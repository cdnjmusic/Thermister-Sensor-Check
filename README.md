# Thermistor Sensor Temperature Monitor 🌡️

![Arduino UNO](https://img.shields.io/badge/Arduino%20UNO-Compatible-brightgreen)
![Thermistor Sensor](https://img.shields.io/badge/Thermistor-Sensor-blue)

## Overview 🌟

🤖 Keep your cool with this adorable temperature monitoring system using Arduino UNO, LEDs, and a thermistor sensor! 🌡️

<a href="https://wokwi.com/projects/376191748870785025">Project Fork Link</a>

## Hardware Setup 🛠️

🔌 Connect the dots to set up your system:

<a href="https://user-images.githubusercontent.com/cdnjmusic/Thermister-Sensor-Check/wiring-diagram.png">
  <img src="https://user-images.githubusercontent.com/cdnjmusic/Thermister-Sensor-Check/wiring-diagram.png" alt="Wiring Diagram">
</a>

1. 🌡️ Attach the thermistor and a 10K resistor in series.
2. 🧊 Link the thermistor-resistor junction to analog pin A0 on the Arduino.
3. 💚 Connect Green LED to pin 2, Yellow LED to pin 3, and Red LED to pin 4.
4. ⚡ Wire the LED cathodes to GND through the appropriate resistors.
5. 🤖 Power up your Arduino UNO!

## Code 🚀

```arduino
const float BETA = 3950; // Beta Coefficient of the thermistor
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
  
  // Using Steinhart-Hart Equation
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  
  // LED control based on temperature
  // ...
  delay(1000);
}
```

## Usage 🚴

1. Upload the code to your Arduino UNO.
2. 📊 Open the Serial Monitor to see temperature readings.
3. 🌈 Watch LEDs change colors with temperature!

Enjoy your cute temperature monitor! 🌞❄️🔥

---

Tasked by *Uri Shaked* to *Riddhiman* via *Blackbird Job Simulation | Forage* 🤖

[GitHub Repo](https://github.com/cdnjmusic/Thermister-Sensor-Check) | [Report Issues](https://github.com/cdnjmusic/Thermister-Sensor-Check/issues)

⭐ Star this repo if you find it adorable! ⭐
