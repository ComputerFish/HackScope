int ftpsPin = A0;  // FTPS connected to analog pin A0

void setup() {
  Serial.begin(115200);  // High baud rate for smooth plotting
  Serial.println("Start"); // Helps Serial Plotter detect data
}

void loop() {
  int sensorValue = analogRead(ftpsPin);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to voltage

  // Convert voltage to pressure (-10 kPa to +10 kPa range, adjust if needed)
  float pressure = ((voltage - 0.5) / 4.0) * 20 - 10;

  // Output formatted data for Serial Plotter
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" ");

  Serial.print("Pressure: ");
  Serial.println(pressure);  // Serial Plotter treats each newline as a new data point

  delay(100);  // Reduce delay for smoother graph
}
