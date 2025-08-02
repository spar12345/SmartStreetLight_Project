// Pin definitions
const int ldrPin = A0;           // LDR connected to A0
const int ir1 = 2, ir2 = 3, ir3 = 4; // IR sensors
const int led1 = 5, led2 = 6, led3 = 7; // LEDs for street lights

void setup() {
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  Serial.begin(9600); // For debugging
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int threshold = 500; // Adjust based on room light

  // Check if it's night
  if (ldrValue < threshold) {
    // IR sensor 1
    if (digitalRead(ir1) == LOW) {
      digitalWrite(led1, HIGH);
    } else {
      digitalWrite(led1, LOW);
    }

    // IR sensor 2
    if (digitalRead(ir2) == LOW) {
      digitalWrite(led2, HIGH);
    } else {
      digitalWrite(led2, LOW);
    }

    // IR sensor 3
    if (digitalRead(ir3) == LOW) {
      digitalWrite(led3, HIGH);
    } else {
      digitalWrite(led3, LOW);
    }

  } else {
    // It's day time, all lights off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  delay(100);
}

