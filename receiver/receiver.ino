// RECEIVER CODE
// (this code is not mine)
// source: http://www.instructables.com/id/Wirelessly-Control-A-Robot-Using-Arduino-and-RF-Mo/?ALLSTEPS

  #include <Servo.h>
  #include <VirtualWire.h>

// here are the servos
Servo bigservo1;
Servo bigservo2;
Servo smallservos;
Servo clawmotor;
Servo vexes;

// motor pins!

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
int x = 0;

void setup() {
  Serial.begin(9600);  // Debugging only
  Serial.println("setup");
  // Initialise the IO and ISR
  vw_setup(2000);  // Bits per sec
  vw_set_rx_pin(11);//Receiver at Digital Pin 11
  vw_rx_start();// Start the receiver PLL running

  bigservo1.attach(9);
  bigservo2.attach(7);
  smallservos.attach(10);
  clawmotor.attach(3);
  vexes.attach(8);

  // button pins are inputs
  pinMode(cbpin, INPUT);
  pinMode(vbpinfw, INPUT);
  pinMode(vbpinbw, INPUT);


}//close setup

void loop()
{
  
  
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(13, true); // Flash a light to show received good message
  // Message with a good checksum received, dump it.
  
  for (i = 0; i < buflen; i++)
  {
      Serial.print(buf[i]);
        if(buf[i] == 'f')
        {
          //forward(); go forward when f is pressed
        }
        
        if(buf[i] == 'b')
      {
        //backward();//go backward when b is pressed
      }
      
        if(buf[i] == 'c')
      {
        cbstate = HIGH;
      }

        if(buf[i] == 'x')
      {
        cbstate = LOW;
      }

      if (cbstate == HIGH) {
        clawmotor.write(170);
        x = 0;
      } if (cbstate == LOW) {
          if (x == 0) {
            clawmotor.write(50);
            delay(500);
            x = 1;
          } else {
            clawmotor.write(90);
          }}
      
  }//close for loop
  
        digitalWrite(13, false);

   }//close main if
}//close loop
//you can print the data entered when debugging by adding Serial.println

////////////////////////////////////////////////////////////////////////////////////////

// shoulder = bigs, elbow = vexes, wrist = smalls, claw = claw vex

//set of functions
//
//void shoulder()
//{
//  digitalWrite(bigservo1,LOW);
//  digitalWrite(bigservo2,LOW);
//  digitalWrite(spallservos,LOW);
//  digitalWrite(clawmotor,LOW);
//  digitalWrite(vexes,LOW);
//  }

  //End Of Code
