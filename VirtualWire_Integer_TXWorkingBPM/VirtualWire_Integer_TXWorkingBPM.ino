/* 
 
 Sensor Transmitter 
 By Markus Ulfberg 2012-07-06
 
 Takes a sensor reading 0-1023
 converts it to a char array and sends 
 to RF receiver unit via VirtualWire  
 
 */

#include <VirtualWire.h>

// LED's
const int blinkPin = 13;          // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

// Sensors 
const int pulsePin = A2;

int Sensor1Data;
char Sensor1CharMsg[4]; 

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, the Inter-Beat Interval
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

void setup() {
  
   // Initialise the IO and ISR
  //vw_set_ptt_inverted(true); // Required for DR3100
  // VirtualWire setup
  vw_setup(2000);	 // Bits per sec

  // LED 
  pinMode(blinkPin,OUTPUT);          // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  // Sensor
  //pinMode(pulsePin,INPUT);

  // for debugging
  Serial.begin(9600);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS  

}

void loop() {

  // Read and store Sensor 1 data
  Sensor1Data = BPM;

  // Convert integer data to Char array directly 
  itoa(Sensor1Data,Sensor1CharMsg,10);

  //QS finds a heartbeat
  if (QS == true){                       // Quantified Self flag is true when arduino finds a heartbeat
    fadeRate = 255;                  // Set 'fadeRate' Variable to 255 to fade LED with pulse
    QS = false;                      // reset the Quantified Self flag for next time 

    // END DEBUG

    digitalWrite(13, true); // Turn on a light to show transmitting
    vw_send((uint8_t *)Sensor1CharMsg, strlen(Sensor1CharMsg));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false); // Turn off a light after transmission 

  } // END void loop...

  ledFadeToBeat();

  //delay(20);       
}


void ledFadeToBeat(){
  fadeRate -= 15;                         //  set LED fade value
  fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
  analogWrite(fadePin,fadeRate);          //  fade LED
}  // 

