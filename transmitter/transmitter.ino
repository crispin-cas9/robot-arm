
// TRANSMITTER CODE
// (this code is not mine)
// source: http://www.instructables.com/id/Wirelessly-Control-A-Robot-Using-Arduino-and-RF-Mo/?ALLSTEPS

//NOTE :- THIS CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE COMPUTER!!!!

#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
     
    vw_setup(2000);  // Bits per sec
        vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
}//close setup

void loop()
{
  
  if (Serial.available() > 0)
  {
     int sendByte = Serial.read();//Starts reading data from the serial monitor once condition is met
     
 
  switch (sendByte){
 
    case 'f':  //if controller types f
  {
    
    char msg2[] = "f";
    digitalWrite(13, HIGH); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    break;
     
  }
    case 'b':  //if controller types b
    {
   char msg2[] = "b";
   digitalWrite(13, HIGH); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);  
   break;
    }

    default://if any other value is entered
    {
      
       Serial.println("wrong entry");//print wrong entry in the serial monitor
    }
   }// close switch-case
  }//close if 
 }//close loop
  
 // End Of Code 
