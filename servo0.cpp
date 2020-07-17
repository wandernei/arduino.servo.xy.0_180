#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("-------------------------");
  Serial.println("Starting Arduino....");
  delay(1000);
  Serial.println("Starting Servo Control by Serial Monitor...");
  Serial.println("-------------------------");
  myservo.attach(9);
  Serial.println("Moving Servo to the limits...");

  for(pos = 0; pos <= 180; pos += 1)

  delay(30);
  Serial.println("Go to 0 degrees....");
  myservo.write(0);

  delay(1000);
  Serial.println("Go to 180 degrees....");
  myservo.write(180);

  delay(1000);
  Serial.println("Go to 90 degrees....");
  myservo.write(90);

  delay(1000);
  Serial.println("servo calibrated");
  Serial.println("-------------------------");
  Serial.println("Input an angle between 10 and 170 degrees... and press Enter...");
  Serial.println("-------------------------");
}

void loop() {
  for(pos = 0; pos <= 180; pos += 1)

  if (Serial.available())
  {
    int state = Serial.parseInt();

    if (state < 10 || state >170)
    {
      if(state==0) {
//        Serial.println("0 is out of 10 to 170 range");
        Serial.println(">");
        break;
      }
      Serial.println(state);
      Serial.println("out of range, 10 - 170 degrees");
    }

    if (state >= 10 && state <= 170)
    {
      if(state==0) {
//        Serial.println("0 is out of 10 to 170 range");
        Serial.println(">");
        break;
      }
      Serial.println("Moving servo to "+String(state)+" degrees.");
      myservo.write(state);
    }
        
  }

}
