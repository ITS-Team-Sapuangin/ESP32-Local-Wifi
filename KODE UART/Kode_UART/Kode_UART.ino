void setup() {
  // Start the Serial Monitor at a baud rate of 115200
  Serial.begin(115200);
  
  // Print an initial message to the Serial Monitor
  Serial.println("ESP32 is ready. Please enter a message:");
  
  // Define Pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Check if data is available in the Serial buffer
  while (Serial.available()) {
    // Read the input from Serial Monitor
    String input = Serial.readString();
    // Change the Type of Data to int
    int x = input.toInt();
    // Logic
    if(x == 1)
    {
      // If u input 1 on serial monitor the LED will turn ON
      digitalWrite(LED_BUILTIN, HIGH);
      
      // If u input other than 1 on serial monitor the LED will turn OFF
    } else {
    digitalWrite(LED_BUILTIN, LOW);
    }
  }