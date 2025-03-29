# Hacking together a simple oscilloscope to fix my car
![Setup](https://github.com/user-attachments/assets/694c1762-d669-4e99-b1a1-d275db9a0e99)

## Overview

This project is a simple Arduino-based oscilloscope designed to read and visualize the fuel tank pressure sensor (FTPS) data from a vehicle’s EVAP system. The goal is to diagnose potential issues by monitoring pressure fluctuations in real time using the Arduino IDE Serial Plotter.

## Why This Project?

My car had an issue with the EVAP system, and I needed to verify whether the EVAP pressure sensor was outputting correct values. Instead of using an expensive diagnostic tool, I used this as an opportunity to build something myself. I used an Arduino to read the sensor’s voltage, convert it into pressure values, and plot the waveform while the engine was running.

## Some Background on the Issue

I have an EVAP issue in my engine. *What is the EVAP system?* Most modern cars take advantage of the fact that fuel vapors evaporate from the fuel tank and allow these vapors to vent into the combustion chamber for maximum efficiency. The EVAP system continuously monitors these fuel vapors, and my car was indicating a major issue by reporting ECU error codes.

I had already spent a good amount of time digging through MINI Cooper forums looking for common causes of these error codes. First, I changed the gas cap, which often fails and prevents a proper vacuum from forming, but that wasn’t the issue. Next, I replaced my purge valve it's a simple solenoid that regulates vapor pressures sent to the engine but that also didn’t fix it.

Finally, I suspected the fuel tank pressure sensor (FTPS) as the last possible culprit. I didn’t want to replace this part blindly, as it was quite expensive. Instead, I devised a plan to confirm my suspicions before ordering a new part.

I knew the sensor had three wires, and from my previous experience with sensors, this likely meant the following configuration:
```
VDD – Power (Voltage)
GND – Ground
SIG – Signal
```
**My idea was simple**: run the engine as usual, tap into the signal wire, and read out the voltage values. If the data was erratic or inconsistent, it would indicate a sensor malfunction. But before testing it on the car, I decided to perform a bench test to establish a baseline.

## Let's get some data!
![Bench testing](https://github.com/user-attachments/assets/b4818cc0-cd37-493f-aba8-583ce40601b8)

So it seemed to me like a good idea to remove the sensor from the car and get some baseline readings to see what we are working with. In order to do this I had to
 solder some wires to the connector which wasn't too hard and then I had to wire up the arduino and think of how I am going to aporach reading data from this device, with no documentation available I had to just go off instinct to what I thought would work for a sensor like this.
### 


