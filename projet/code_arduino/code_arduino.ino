void setup() {
  Serial.begin(9600);       // Initialize serial at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char incoming = Serial.read();
    
    // If 'C' is received, respond with 'A' and blink LED
    if (incoming == 'C') {
      Serial.write('A');
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}