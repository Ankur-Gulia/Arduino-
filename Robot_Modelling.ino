// ACS6503 Manipulator Robotics 
// Robot Modelling
// Author: Pranav and Ankur
// University of Sheffield
// Date: Septemeber 2022


// Include the servo library to allow for connection and control of servo motors
#include <Servo.h>  
Servo servo1; 
Servo servo2;
// // define the macro pinServo1 and pinServo2, to use for connecting the servo to pin 12 and pin 13
#define pinServo1 12
#define pinServo2 13

//************  BASE MOTOR FOR WHEEL **********************

const int pinAI1 = 7;        // Pin allocation for AI1 - left motor(base)
const int pinAI2 = 8;        // Pin allocation for AI2 - left motor(base)
const int PWM1 = 5;          // Pin allocation for the PWM pin - left motor(base)
const int pinStandBy = 9;    // Pin allocation for the standby pin
const int pinBI1 = 10;       // Pin allocation for BI1 - right motor(base)
const int pinBI2 =11;        // Pin allocation for BI2 - right motor(base)
const int PWM2 = 3;          // Pin allocation for the PWM pin - right motor(base)

boolean AI1 = 0;            // AI1 pin value
boolean AI2 = 0;            // AI2 pin value
boolean standBy = 0;        // standBy pin Value
boolean BI1 = 0;            // BI1 pin value
boolean BI2 = 0;            // BI2 pin value
boolean rotDirect = 0;      // Rotation direction variable
unsigned char pwmValue1 = 0; // PWM value to be written to the output for left motor 
unsigned char pwmValue2 = 0; // PWM value to be written to the output for right motor

//*************   SERVO MOTOR FOR ARM *******************

int angle1= 0;               // Angle for Servo 1 - First arm
int angle2= 0;               // Angle for Servo 2 - Second arm (connection for marker)
int buttonPin=2;               // Pin allocation for switch 
int buttonState;               // Variable for Button state  

//*************  SENSOR PIN DEFINATION *********************
const int trigPin1= A0;         // trigger for centre sensor
const int trigPin2= A1;         // trigger for left sensor
const int trigPin3= A2;         // trigger for right sensor
const int echoPin1= A3;         // echo for centre sensor
const int echoPin2= A4;         // echo for left sensor
const int echoPin3= A5;         // echo for right sensor



long duration1;              // Duration for sensor - centre
long duration2;              // Duration for sensor - left
long duration3;              // Duration for sensor - right
int distance1;               // Distance for sensor - centre
int distance2;               // Distance for sensor - left
int distance3;               // Distance for sensor - right


//************* SUPPORTING FUNCTION DECLARATION ***************************

void Bot_forward();
void Bot_Reverse();
void Bot_turn_left();
void Bot_turn_right();
void Bot_stop();
void arm1_turn();
void sensor_centre();
int draw = 0;
//************ INITIAL SETUP ********************************
void setup() {
    //Initialize the serial port
  Serial.begin(9600);

    // Assign the digital I/O pin directions
  pinMode(pinAI1, OUTPUT);
  pinMode(pinAI2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(pinStandBy, OUTPUT);
  pinMode(pinBI1, OUTPUT);
  pinMode(pinBI2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
   // "attach"  servo 1 to the defined pin
  servo1.attach(pinServo1);
    // "attach"  servo 1 to the defined pin
  servo2.attach(pinServo2);
  // Drive the standby pin high to enable the output
  standBy = true;
  digitalWrite(pinStandBy, standBy);
  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false;
  BI1 = true;
  BI2 = false;
  // set an initial value for the PWM value
  pwmValue1 = 100;
  pwmValue2 = 100;
  angle1 = 100;
  servo1.write(angle1);

  pinMode(buttonPin, INPUT);
}

//**************** MAIN CONDITION *****************************
void loop() {
  delay(5);
  sensor_centre();
  // Prints the distance at centre to the Serial Monitor
  Serial.print("Distance1: ");
  Serial.println(distance1);

 // Intial condition for robot motion
  Bot_forward();
//  for(int i = 1; i<5; i++){

//      sensor_centre();
  if (distance1 < 17 ){
//        if (i==1){
    if(draw == 1){
        delay(150);
        Bot_stop();
        delay(100);
        servo1.write(120);
        delay(500);
        servo1.write(70);
        delay(500);
        servo1.write(100);
        delay(500);
        Bot_turn_left();
        delay(1400);
        }
        
else if(draw == 3){
    Bot_stop();
  delay(500);
  Bot_forward();
  delay(5000);
}
else{
         Bot_turn_left();
         delay(1400);  
}
    ++draw;
}
}

//************* SUPPORTING FUNCTION ***************************

void Bot_forward(){

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false; 

  // Set Initial values for BI1 and BI2 control function pins
  BI1 = true;
  BI2 = false;

  pwmValue2=59; //right
  pwmValue1=57; //left
  

// Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
// Write the pwnValue to the PWM pin
   analogWrite(PWM1, pwmValue1);
   analogWrite(PWM2, pwmValue2); 
 //     angle1=130;
  // servo1.write(angle1);
}

void Bot_Reverse(){

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = false;
  AI2 = true; 

  // Set Initial values for BI1 and BI2 control function pins
  BI1 = false;
  BI2 = true; 

  pwmValue2=70;
  pwmValue1=70;
  // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
// Write the pwnValue to the PWM pin
   analogWrite(PWM1, pwmValue1);
   analogWrite(PWM2, pwmValue2);  
}
void Bot_turn_left(){
  // Set Initial values for AI1 and AI2 control function pins
  AI1 = false;
  AI2 = true; 

  // Set Initial values for BI1 and BI2 control function pins
  BI1 = true;
  BI2 = false; 

  pwmValue2=60;
  pwmValue1=53;

  // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
// Write the pwnValue to the PWM pin
   analogWrite(PWM1, pwmValue1);
   analogWrite(PWM2, pwmValue2);  
  //     angle1=130;
  //  servo1.write(angle1);
  
}

void Bot_turn_right(){

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false; 

  // Set Initial values for BI1 and BI2 control function pins
  BI1 = false;
  BI2 = true; 

  pwmValue2=70;
  pwmValue1=70;
  // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
// Write the pwnValue to the PWM pin
   analogWrite(PWM1, pwmValue1);
   analogWrite(PWM2, pwmValue2);  

}
void Bot_stop(){

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false; 

  // Set Initial values for BI1 and BI2 control function pins
  BI1 = true;
  BI2 = false; 

  pwmValue2=0;
  pwmValue1=0;
  // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
// Write the pwnValue to the PWM pin
   analogWrite(PWM1, pwmValue1);
   analogWrite(PWM2, pwmValue2);  
}

void arm1_turn(){
  for(angle1 =100; angle1 <60; angle1 -= 1) 	 // command to move from 0 degrees to 180 degrees 
  {                                  
    servo1.write(angle1);              	 //command to rotate the servo to the specified angle
    delay(15); 
} 
  delay(1000);
 
 for(angle1 =60; angle1 >90; angle1 +=5)     // command to move from 180 degrees to 0 degrees 
   {                                
    servo1.write(angle1);              //command to rotate the servo to the specified angle
    delay(5);                       
 } 
}

void sensor_centre(){
   // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;

}