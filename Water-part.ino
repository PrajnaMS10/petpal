// Define pin numbers
const int waterLevelSensorPin = 2;  // Digital pin for water level sensor
const int pumpRelayPin = 3;          // Digital pin for pump relay
const int pumpDuration = 5000;       // Pump activation duration in milliseconds (adjust as needed)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pins modes
  pinMode(waterLevelSensorPin, INPUT);
  pinMode(pumpRelayPin, OUTPUT);
}

void loop() {
  // Read water level sensor
  int waterLevel = digitalRead(waterLevelSensorPin);
  
  // Check water level
  if (waterLevel == HIGH) {
    Serial.println("Water level is low. Refilling bowl...");
    
    // Activate pump
    digitalWrite(pumpRelayPin, HIGH);
    delay(pumpDuration);
    digitalWrite(pumpRelayPin, LOW);
    
    Serial.println("Refilling complete.");
  } else {
    Serial.println("Water level is okay.");
  }
  
  // Add some delay to avoid continuous checking
  delay(1000);
}