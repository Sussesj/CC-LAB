

int LDR = 2;       // select the input pin for the LDR
int ledBlue = 9;   // select the pin for the LED
int ledGreen = 10;
int ledRed = 11;
int val = 0;       // variable to store the value coming from the sensor


void setup() {
  pinMode(LDR, INPUT);       // declare the LDR as an INPUT
  pinMode(ledBlue, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  Serial.println(9600);
    
}

void loop() {
  Serial.begin(9600);
  val = analogRead(LDR);       // read the value from the sensor
  
   color(255, 0, 0);	// turn the RGB LED red
          delay(val*1000);	// delay for 1 second
          color(0,255, 0);	// turn the RGB LED green
          delay(val*1000);	// delay for 1 second
          color(0, 0, 255);	// turn the RGB LED blue
          delay(val*1000);	// delay for 1 second
 
//          // Example blended colors:
//          color(255,255,0);	// turn the RGB LED yellow
//          delay(1000);	// delay for 1 second
//          color(255,255,255);	// turn the RGB LED white
//          delay(1000);	// delay for 1 second
//          color(128,0,255);	// turn the RGB LED purple
//          delay(1000);	// delay for 1 second
//          color(0,0,0);	// turn the RGB LED off
//          delay(1000);	// delay for 1 second
}
 // Basic colors:	 
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(ledRed, 255-red);	 
          analogWrite(ledBlue, 255-blue);
          analogWrite(ledGreen, 255-green);
}	 
 	 
