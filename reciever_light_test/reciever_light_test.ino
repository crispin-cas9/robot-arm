// RECEIVER CODE test
// (this code is not mine)
// source: http://www.instructables.com/id/Wirelessly-Control-A-Robot-Using-Arduino-and-RF-Mo/?ALLSTEPS

  #include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_rx_pin(2);//Receiver at Digital Pin 2
    vw_rx_start();// Start the receiver PLL running

    pinMode(3, OUTPUT);

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
        if(buf[i] == 'f') {
          digitalWrite(3, HIGH);
        }
        if(buf[i] == 'b') {
          digitalWrite(3, LOW);
        }
  }//close for loop
  
        digitalWrite(13, false);

   }//close main if
}//close loop
//you can print the data entered when debugging by adding Serial.println

  //End Of Code
