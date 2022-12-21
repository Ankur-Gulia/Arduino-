// This Example code is for use with the Controlling a Standard Servomotor exercise
//

// Include the servo library to allow for connection and control of servo motors
#include <Servo.h>

// define the macro pinServo1 as 9, to use for connecting the servo to pin 9
#define pinServo1 9

// Declare a servo motor class variable servo 1
Servo servo1;
int potAnalogpin = 0;
int val;

// -------------------------------------
// Setup function
void setup()
{
  // "attach"  servo 1 to the defined pin
  servo1.attach(pinServo1);
  // Alternte command for setting the neutral position
  //servo1.writeMicroseconds(1500);

  // wait until the servo has moved into position, (1000ms is more time than needed)
  delay(1000);
}

// -------------------------------------
// Loop Function
void loop()
{
  val = analogRead(potAnalogpin);
  val = map(val*1,0,1023,0,360);
  servo1.write(val);

  delay(150);

}
