# DIY Arduino Oscilloscope to Diagnose My Car's EVAP Issue

![Setup](https://github.com/user-attachments/assets/694c1762-d669-4e99-b1a1-d275db9a0e99)

*When your car throws mysterious error codes, why not build a tool to investigate it yourself?*

---

## 🧠 Project Overview

This is a simple Arduino-based oscilloscope designed to read and visualize the fuel tank pressure sensor (FTPS) data from a car’s EVAP system. The goal: monitor pressure changes in real time using the Arduino IDE’s Serial Plotter and figure out if the sensor is causing the issue, without buying expensive diagnostics tools.

---

## 🚗 Why This Project?

My car (a MINI Cooper) was showing EVAP related check engine codes, and I needed to figure out whether the fuel tank pressure sensor was the cause. Instead of blindly replacing parts or investing in an automotive scan tool, I took a more hands-on route.

Using an Arduino, I tapped into the sensor’s signal wire to:

- Read analog voltage values  
- Convert those voltages to pressure readings  
- Plot the data live while the engine runs

---

## 🔧 Background: What's Going On?

### What is the EVAP system?

The EVAP (Evaporative Emissions Control) system captures fuel vapor from the tank and routes it into the engine for combustion improving efficiency and reducing emissions. When there’s a leak or fault, the ECU sets a trouble code.

I dove into forums and found the usual suspects: gas cap, purge valve, etc.

- ✅ Replaced the gas cap — still getting the code.  
- ✅ Swapped the purge valve — no improvement.

Eventually, I focused on the **fuel tank pressure sensor** — a more expensive part. I didn’t want to replace it without confirming it was the issue. So, I reverse engineered a test.

---

## 🔌 Understanding the Sensor Wiring

The FTPS had three wires, which typically means:
```
VDD – Power (usually 5V)
GND – Ground
SIG – Signal (analog voltage output)
```

The idea: tap into the signal line while the engine is running and monitor live voltage. If the readings are unstable, it might confirm the sensor is faulty.

Before testing in the car, I started with a clean **bench test** to get baseline data.

---

## 🧪 Bench Testing the Sensor

| | |
| ------------- | ------------- |
|![Bench testing](https://github.com/user-attachments/assets/b4818cc0-cd37-493f-aba8-583ce40601b8)|![IMG_9756](https://github.com/user-attachments/assets/83956cf6-9975-4a8a-8e43-051a5b839bf5)|

I removed the sensor, soldered a few wires to the connector, and connected it to an Arduino. With no datasheet available, I used trial and error to figure out what worked — and to my surprise, I got clean, stable voltage output.

✅ **Success:** The sensor seems to function correctly *off the car*.

---

## 🔌 Reinstalling and Testing In-Car

| | |
| ------------- | ------------- |
|![IMG_9767](https://github.com/user-attachments/assets/dc67d68b-02b4-4f76-9914-15c44c14f099)|![IMG_9770](https://github.com/user-attachments/assets/e233c0c1-4231-4f19-81a7-35a96a60818c)|
![IMG_9773](https://github.com/user-attachments/assets/b56fe8bc-e8b2-4724-b946-646521a7e590)|![IMG_9785](https://github.com/user-attachments/assets/e6fe8013-2d51-44d5-815b-139803b90788)

To get real-world data, I reinstalled the sensor and tapped into the signal wire without cutting it — just a shallow scrape to expose some copper and soldered a lead to it.

With the Arduino hooked back up, I was ready to log data while the engine ran.

---

## 🧰 Arduino Code

Here’s the code I used to collect and plot the sensor data. It reads an analog voltage, converts it to pressure (assuming a -10 to +10 kPa range), and sends it to the Serial Plotter.

```cpp
const int ftpsPin = A0; // Analog pin connected to sensor signal

void setup() {
  Serial.begin(115200); // High baud rate for smoother plotting
  Serial.println("Start"); // Helps Serial Plotter initialize
}

void loop() {
  int sensorValue = analogRead(ftpsPin);
  
  // Convert analog reading (0-1023) to voltage (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert voltage to pressure in kPa (-10 to +10 range, example)
  float pressure = ((voltage - 0.5) / 4.0) * 20 - 10;

  // Output values for Serial Plotter
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("  Pressure: ");
  Serial.println(pressure);
  
  delay(100); // Small delay for smoother graph
}
```

## 📊 Live Data Results

![Live data](https://github.com/user-attachments/assets/1c464572-7084-45a7-bc1b-90700d530a82)


This is what the Serial Plotter showed while the engine was running. The voltage and pressure readings were unstable enough to make me confident that the sensor wasn't working correctly.

## 🤔 What I’d Do Differently

This was a quick and effective project, but there’s always room to improve:

⚡ Electrical Noise: Cars generate tons of interference. My test setup didn’t filter any of it. A small capacitor between signal and ground could have helped smooth out the readings.

🧲 Ground Loop: I didn’t tie the Arduino’s ground to the car’s ground. That could have introduced noise too.

📐 Enclosure & Vibration Isolation: The Arduino was bouncing around a bit in the engine bay — not ideal.
Still, it worked well enough to identify the issue.

## ✅ Conclusion: Replace the Sensor

In the end, this DIY oscilloscope confirmed that the FTPS was misbehaving under load. It’s fun to think about reverse-engineering a replacement, but these sensors are rugged and complex — not something I’d want to replicate for a weekend project.

So: I bought a new sensor, installed it, and cleared the code. Problem solved.



