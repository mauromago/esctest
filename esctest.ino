
#include <Servo.h> 
int val;    // variable to read the value from the analog pin

Servo myservo;  // create servo object to control a servo 
void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  // check if data has been sent from the computer:
  if (Serial.available()) {
    val = Serial.read();
    val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
    myservo.write(val);                  // sets the servo position according to the scaled value 
    delay(15);
  }
}
