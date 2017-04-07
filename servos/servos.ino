
// Robot Arm servo code
// (+ annotations!)
// by Finley

// we're gonna be working with servos yay
#include <Servo.h>

// here are the servos
Servo bigservo1;
Servo bigservo2;
Servo smallservos;
Servo clawmotor;
Servo vexes;

// here are the variables
int potpin1 = A0;
int potpin2 = A1;
int cbpin = 2;
int vbpinfw = 4;
int vbpinbw = 5;
int val1;
int val2;
int val3;
int cbstate = 0;
int vbstatef = 0;
int vbstateb = 0;
int i = 0;

// set up the things (only runs once)
// tell it what servos recieve signal from which pins
void setup() {
  bigservo1.attach(9);
  bigservo2.attach(7);
  smallservos.attach(10);
  clawmotor.attach(3);
  vexes.attach(8);

  // button pins are inputs
  pinMode(cbpin, INPUT);
  pinMode(vbpinfw, INPUT);
  pinMode(vbpinbw, INPUT);
  
}

// to be repeated... FOREVER
void loop() {
  val1 = analogRead(potpin1);   // reads the value of the potentiometers
  val2 = analogRead(potpin1);
  val3 = analogRead(potpin2);
  val1 = map(val1, 0, 1023, 0, 180);    // converts to degrees (value between 0 and 180)
  val2 = map(val2, 0, 1023, 180, 0);
  val3 = map(val3, 0, 1023, 0, 180);
  bigservo1.write(val1);      // and sets the servos to the right degree
  bigservo2.write(val2);
  smallservos.write(val3);
  delay(15);

  // read the state of the button values
  cbstate = digitalRead(cbpin);
  vbstatef = digitalRead(vbpinfw);
  vbstateb = digitalRead(vbpinbw);

  // check if the button is pressed
  // if it is (HIGH state), turn on the motor
  // if it's not (LOW state):
  // make it go back to its original position
  // and turn it off

  if (cbstate == HIGH) {
    clawmotor.write(170);
    i = 0;
  } if (cbstate == LOW) {
      if (i == 0) {
        clawmotor.write(50);
        delay(500);
        i = 1;
      } else {
        clawmotor.write(90);
      }}

// this is for the other two vex motors, controlled by two buttons
// it checks the state of the buttons (if they're pushed or not)
// and sets the vex speed accordingly

// if forward is pushed and backward isn't, go forward
  if (vbstatef == HIGH && vbstateb == LOW) {
    vexes.write(170);
  }

// if backward is pushed and forward isn't, go backward
  else if (vbstateb == HIGH && vbstatef == LOW) {
    vexes.write(50);
  }

// if neither are pushed, do nothing
  else if (vbstateb == LOW && vbstatef == LOW) {
    vexes.write(90);
  }

// if both are pushed, do nothing
  else if (vbstateb == HIGH && vbstatef == HIGH) {
      vexes.write(90);
  }

}

