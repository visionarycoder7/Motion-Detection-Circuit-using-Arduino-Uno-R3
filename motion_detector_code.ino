// --- PIN DEFINITIONS ---
// Digital pin connected to the PIR sensor's OUT pin
const int pirPin = 2;

// Digital pin for the alarm LED
const int ledPin = 13;

// Digital pin for the Piezo Buzzer
const int buzzerPin = 8;

// Variable to store the current state of the PIR sensor (HIGH or LOW)
int motionState = 0; 

// Variable to track the alarm status to print messages only once
int alarmStatus = LOW; 

void setup() {
  // Initialize the pins
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Start serial communication to monitor status in the Tinkercad console
  Serial.begin(9600);
  Serial.println("--- Motion Detector Armed ---");
  
  // Give a short beep to confirm the system is armed
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  delay(500);
}

void loop() {
  // Read the state of the PIR sensor (HIGH if motion detected, LOW otherwise)
  motionState = digitalRead(pirPin); 

  if (motionState == HIGH) {
    // --- MOTION DETECTED ---
    
    // 1. Activate the visual alarm (LED)
    digitalWrite(ledPin, HIGH);
    
    // 2. Activate the audible alarm (Buzzer)
    // We use tone() for a specific frequency, better than digitalWrite(HIGH)
    tone(buzzerPin, 1000); // Play a 1000 Hz tone

    // Check if the alarm just switched ON (to avoid printing the message repeatedly)
    if (alarmStatus == LOW) {
      Serial.println("!!! ALERT: MOTION DETECTED !!!");
      alarmStatus = HIGH; // Update status
    }
    
    // Keep the loop running fast to capture the end of motion quickly
    delay(50);
    
  } else {
    // --- NO MOTION DETECTED ---
    
    // 1. Deactivate the visual alarm
    digitalWrite(ledPin, LOW);
    
    // 2. Deactivate the audible alarm
    noTone(buzzerPin);
    
    // Check if the alarm just switched OFF
    if (alarmStatus == HIGH) {
      Serial.println("System clear. Motion ended.");
      alarmStatus = LOW; // Update status
    }
  }
}
