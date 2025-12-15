#include <Servo.h>

Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4;  
Servo servo5;

void setup() {
  delay(2000); 
  Serial.begin(921600);
  delay(1000);

  servo1.attach(16,0,2500);
  servo2.attach(5,0,2500);
  servo3.attach(4,0,2500);
  servo4.attach(0,0,2500);
  servo5.attach(14,0,2500);

  homePosition();
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    Serial.print("Command: "); Serial.println(cmd);

    if (cmd == "home") {
      homePosition();
    } else if (cmd.startsWith("s1 ")) {  //1st
      int ang = cmd.substring(3).toInt();
      servo1.write(constrain(ang, 0, 180));
      Serial.println("s1 -> " + String(ang) + "°");
    } else if (cmd.startsWith("s2 ")) {  //base
      int ang = cmd.substring(3).toInt();
      servo2.write(constrain(ang, -0, 180));
      Serial.println("s2 -> " + String(ang) + "°");
    } else if (cmd.startsWith("s3 ")) {  //bottom 1st
      int ang = cmd.substring(3).toInt();
      servo3.write(constrain(ang, 0, 180));
      Serial.println("s3 -> " + String(ang) + "°");
    } else if (cmd.startsWith("s4 ")) {  //middle
      int ang = cmd.substring(3).toInt();
      servo4.write(constrain(ang, 0, 180));
      Serial.println("s4 -> " + String(ang) + "°");
    } else if (cmd.startsWith("s5 ")) {  
      int ang = cmd.substring(3).toInt();
      servo5.write(constrain(ang, 0, 180));
      Serial.println("s5 -> " + String(ang) + "°"); // gripper
    } else {
      Serial.println("Invaild Command");
    }
  }
}

void homePosition() {
  Serial.println("Intial: 90 45 90 90 90");
  servo1.write(90); delay(500);
  servo2.write(45); delay(500);  // 
  servo3.write(90); delay(500);
  servo4.write(90); delay(500);
  servo5.write(90); delay(500);  // 
  Serial.println("Finish initialize");
}