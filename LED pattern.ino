const int ledPin1=2; // Led 1
const int ledPin2=3; // Led 2
const int ledPin3=4;// Led 3

void setup() {

pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}

void loop() {

// Sequence  index 0
digitalWrite(ledPin1, LOW);  // turn led 1 off
  digitalWrite(ledPin2, LOW);  // turn led 2 off 
  digitalWrite(ledPin3, LOW);  // turn led 3 off 
delay(500);
// Sequence Index 1
  digitalWrite(ledPin1, HIGH);  // turn led 1 on
  digitalWrite(ledPin2, LOW);  // turn led 2 off 
  digitalWrite(ledPin3, LOW);  // turn led 3 off 

  delay(500);
// Sequence Index 2
  digitalWrite(ledPin1, LOW);  // turn led 1 off
  digitalWrite(ledPin2, HIGH);  // turn led 2 on 
  digitalWrite(ledPin3, LOW);  // turn led 3 off 

  delay(500);
// Sequence Index 3
  digitalWrite(ledPin1, HIGH);  // turn led 1 on
  digitalWrite(ledPin2, HIGH);  // turn led 2 on 
  digitalWrite(ledPin3, LOW);  // turn led 3 off 

  delay(500);
//Sequence index 4
  digitalWrite(ledPin1, LOW);  // turn led 1 off
  digitalWrite(ledPin2, LOW);  // turn led 2 off 
  digitalWrite(ledPin3, HIGH);  // turn led 3 on 

  delay(500);
// Sequence Index 5
  digitalWrite(ledPin1, HIGH);  // turn led 1 on
  digitalWrite(ledPin2, LOW);  // turn led 2 off 
  digitalWrite(ledPin3, HIGH);  // turn led 3 on 

  delay(500);
//Sequence Index 6
  digitalWrite(ledPin1, LOW);  // turn led 1 off
  digitalWrite(ledPin2, HIGH);  // turn led 2 on 
  digitalWrite(ledPin3, HIGH);  // turn led 3 on 

  delay(500);
//Sequence Index 7
  digitalWrite(ledPin1, HIGH);  // turn led 1 on
  digitalWrite(ledPin2, HIGH);  // turn led 2 on 
  digitalWrite(ledPin3, HIGH);  // turn led 3 on 
}

  


  