// Define the pins for the LEDs
const int ledPins[] = {7, 8, 9, 10, 11, 12, 13};

// Define the pins for the ultrasonic sensor
const int trigPin = 5;  // Trig pin connected to digital pin 5
const int echoPin = 6;  // Echo pin connected to digital pin 6

void setup() {
  // Set the LED pins as OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Set the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
 // Ultrasonic sensor code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 //Turn on LEDs sequentially as an object approaches
  for (int i = 0; i < 8; i++) {
    if (distance < (i + 1) * 8) {
      digitalWrite(ledPins[i], HIGH);
      // delay(5);
    } else {
      digitalWrite(ledPins[i-1], LOW);
      //delay(5);
      
    }
    
   
    }
    }
    


 


