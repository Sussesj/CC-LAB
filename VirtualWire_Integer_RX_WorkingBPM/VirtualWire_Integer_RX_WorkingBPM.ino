/* 

Sensor Receiver 
By Markus Ulfberg 2012-07-06

Gets a sensor reading 0-1023 in a char array
from RF Transmitter unit via VirtualWire 
converts char array back to integer

*/

#include <VirtualWire.h>

// LED's
int ledPin = 13;
int alarmPin = 6;

// Sensors 
int Sensor1Data;

//Vibrater
const int motorPin = 3;

// RF Transmission container
char Sensor1CharMsg[4]; 

void setup() {
  Serial.begin(9600);
  
  // sets the digital pin as output
  pinMode(ledPin, OUTPUT);  

  //Vibrating motor
  pinMode(motorPin, OUTPUT);
    
    // VirtualWire 
    // Initialise the IO and ISR
    // Required for DR3100
    vw_set_ptt_inverted(true); 
    // Bits per sec
    vw_setup(2000);	 
    
    // Start the receiver PLL running
    vw_rx_start();       

} // END void setup

void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    // Non-blocking
    if (vw_get_message(buf, &buflen)) 
    {
	int i;
        // Turn on a light to show received good message 
        digitalWrite(13, true); 
	
        // Message with a good checksum received, dump it. 
        for (i = 0; i < buflen; i++)
	{            
          // Fill Sensor1CharMsg Char array with corresponding 
          // chars from buffer.   
          Sensor1CharMsg[i] = char(buf[i]);
	}
        
        // Null terminate the char array
        // This needs to be done otherwise problems will occur
        // when the incoming messages has less digits than the
        // one before. 
        Sensor1CharMsg[buflen] = '\0';
        
        // Convert Sensor1CharMsg Char array to integer
        Sensor1Data = atoi(Sensor1CharMsg);
        
        
        
        
        // DEBUG 
        Serial.print("Sensor 1: ");
        Serial.println(Sensor1Data);
        
        // END DEBUG
                
        // Turn off light to and await next message 
        digitalWrite(13, false);
        
        if(Sensor1Data >= 40) {
         digitalWrite(alarmPin, HIGH);
         digitalWrite(motorPin, HIGH);
         delay(50);
         digitalWrite(alarmPin, LOW);
         digitalWrite(motorPin, LOW);
         delay(50);
        }
    }
}

