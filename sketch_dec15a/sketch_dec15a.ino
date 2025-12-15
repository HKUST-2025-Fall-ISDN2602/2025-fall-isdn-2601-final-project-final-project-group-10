#include <Servo.h>

// Create Servo objects
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo gripperServo;

// Define pin connections
const int basePin = D1;      // GPIO5
const int shoulderPin = D2;  // GPIO4
const int elbowPin = D3;     // GPIO0
const int wristPin = D4;     // GPIO2
const int gripperPin = D5;   // GPIO14

void setup() {
  // Attach each servo to its corresponding pin
  baseServo.attach(basePin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  wristServo.attach(wristPin);
  gripperServo.attach(gripperPin);

  // Move servos to initial position
  baseServo.write(90);      // center
  shoulderServo.write(90);  // center
  elbowServo.write(90);     // center
  wristServo.write(90);     // center
  gripperServo.write(0);    // open gripper
  delay(1000);
}

void loop() {
  // Example: Pick up a cube and move it to target location

  // Step 1: Move base to item
  baseServo.write(60);
  delay(1000);

  // Step 2: Lower arm
  shoulderServo.write(120);
  elbowServo.write(60);
  delay(1000);

  // Step 3: Close gripper to grab item
  gripperServo.write(45); // adjust as needed to grip
  delay(1000);

  // Step 4: Lift arm
  shoulderServo.write(90);
  elbowServo.write(90);
  delay(1000);

  // Step 5: Rotate base to target
  baseServo.write(120);
  delay(1000);

  // Step 6: Lower arm again
  shoulderServo.write(120);
  elbowServo.write(60);
  delay(1000);

  // Step 7: Open gripper to release item
  gripperServo.write(0);
  delay(1000);

  // Step 8: Return to neutral
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  wristServo.write(90);
  gripperServo.write(0);
  delay(3000); // Wait before next loop
}