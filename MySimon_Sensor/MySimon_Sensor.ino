//SIMON-SAY-STYLE GAME Step 2, YURY G. OCT 2012
//This code adds the feature of Simon Saying Something, With Time/Speed Game Mechanic, LEDs, and Sound.
//PINS ARE NOW DECLARED 

//Button Pins
const int redButt = A1;     //  declare pins for buttons
const int yellButt = 9;
const int blueButt = 10;
const int greenButt = 11;

//LED Pins
const int redLED = 3;     //  declare pins for LED's
const int yellLED = 4;
const int blueLED = 5;
const int greenLED = 6;


// Color Code we Use for R,Y,B,G and 1,2,3,4 repectfully
const int redValue = 1;  //  declare values for colors for buttons
const int yellValue = 2;
const int blueValue = 3;
const int greenValue = 4;

const int speakerPin = 2 ;  //declare your speaker pin
int sensorValue = 0;
int outputValue = 0;

int userSays = 0;  //value to hold User Input
int userStep = 0;   //  user step counter


boolean simonDone;
int simonSays[99] ={
};       
int nextStep = 0 ;   

int simonSpeed = 800;


void setup()
{
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);   //Set Pin Mode
  pinMode(yellLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(speakerPin, OUTPUT);    // set speaker to output


  pinMode(redButt, INPUT_PULLUP);  //set pull-up resistors on Buttons, So closing the switch will bring Pin to Ground. 
  pinMode (yellButt,INPUT_PULLUP);
  pinMode (blueButt,INPUT_PULLUP);
  pinMode (greenButt,INPUT_PULLUP);

  //Intro sound
  for(int y=0; y<200; y++) // y+= is changed
  {
    Serial.print("y++");
    Serial.print(" Freq: ");
    Serial.println(y);

    tone(2, y);
    delay(50); //play with delay "ratio"
    noTone(2);
    //Intro Fade LED
    for (int brightness = 0; brightness < 255; brightness++)
    {
      analogWrite(redLED, brightness);
      analogWrite(yellLED, brightness);
      analogWrite(blueLED, brightness);
      analogWrite(greenLED, brightness);
    }
    for (int brightness = 255; brightness >= 0; brightness--) 
    {
      analogWrite(redLED, brightness);
      analogWrite(yellLED, brightness);
      analogWrite(blueLED, brightness);
      analogWrite(greenLED, brightness);
    } 
    }

    //Intro end - 
    tone(speakerPin,100);
    digitalWrite(redLED,HIGH);
    digitalWrite(yellLED,HIGH);
    digitalWrite(blueLED,HIGH);
    digitalWrite(greenLED,HIGH);
    delay(500);
    noTone(speakerPin);
    digitalWrite(redLED,LOW);
    digitalWrite(yellLED,LOW);
    digitalWrite(blueLED,LOW);
    digitalWrite(greenLED,LOW);
    delay(500);
    tone(speakerPin,500);
    digitalWrite(redLED,HIGH);
    digitalWrite(yellLED,HIGH);
    digitalWrite(blueLED,HIGH);
    digitalWrite(greenLED,HIGH);
    delay(500);
    noTone(speakerPin);
    digitalWrite(redLED,LOW);
    digitalWrite(yellLED,LOW);
    digitalWrite(blueLED,LOW);
    digitalWrite(greenLED,LOW);
    tone(speakerPin,1000);
    digitalWrite(redLED,HIGH);
    digitalWrite(yellLED,HIGH);
    digitalWrite(blueLED,HIGH);
    digitalWrite(greenLED,HIGH);
    delay(500);
    noTone(speakerPin);
    digitalWrite(redLED,LOW);
    digitalWrite(yellLED,LOW);
    digitalWrite(blueLED,LOW);
    digitalWrite(greenLED,LOW);
    delay(1000);
  randomSeed(analogRead(0));  
}


void loop ()
{


  if (simonDone == false)    
  {
    simonSays[nextStep] = random(1,5) ;

    Serial.print("nextStep: " );    
    Serial.println(nextStep);
    Serial.print("simonSays: ");

    for (int i =0; i <= nextStep ; i++)  
    {
      Serial.print(simonSays[i]);      
      Serial.print(" , ");
      delay(simonSpeed);      // controls speed that simonSays something  

      playToneAndLight(simonSays[i]);   

    }

    simonSpeed= (simonSpeed - (nextStep*5));  //  This seeds up Simon on each turn by forumla (500-(nextStep*5). 
    //  Change the multiplier (5 in this case) to make game faster or slower 
    //  The multiplier is MAJOR factor in how hard the game is. 
    //   This sets Simon's TOP SPEED. Also important in making game interesting yet winable.                                         
    simonSpeed = max(simonSpeed, 400);   //this maxes out simon speed at 200 ms
    simonDone = true; 

    Serial.print("simonSpeed: " );    // Show how the new time feature works
    Serial.println(simonSpeed);         // Show how the new time feature works  
    Serial.println(" "); 

    nextStep++;    //  add one more step to simon's sequence 
    userStep = 0;  // make the user step from the first step
  }

//---------------------------------------------RED Button---------------------------------------------------//
  if (simonDone == true)  
  {
    // listen for user input
    if (userStep < nextStep) 
    {
        sensorValue = analogRead(redButt);  // read the analog in value:          
        // map it to the range of the analog out:
        outputValue = map(sensorValue, 0, 1023, 0, 255);
               // print the results to the serial monitor:
                Serial.println("sensor = " );                       
                Serial.println(sensorValue);   
 
       // wait 2 milliseconds before the next loop for the analog-to-digital converter to settle after the last reading:
      delay(2);   
  
  if (sensorValue <= 70) 
     //(digitalRead(redButt) == LOW)  //redButt was pressed
      {   
        userSays = redValue;
        if(userSays == simonSays[userStep])
        {
          playToneAndLight(redValue);
          userStep++;               
        }
        else
        {
          playToneAndLight(redValue);
          youLose();
        }
      }
//-----------------------------------------Yellow Button------------------------------//

      if (sensorValue = analogRead(yellButt));  // read the analog in value:          
        // map it to the range of the analog out:
        outputValue = map(sensorValue, 0, 1023, 0, 255);
  
               // print the results to the serial monitor:
              Serial.println("sensor = " );                       
              Serial.println(sensorValue);   
 
       // wait 2 milliseconds before the next loop for the analog-to-digital converter to settle after the last reading:
      delay(2);   
  
  if (sensorValue <= 70) 
    //(digitalRead(yellButt) == LOW)
      {  
        userSays = yellValue;
        if(userSays == simonSays[userStep])
        {
          playToneAndLight(yellValue);
          userStep++;
        }
        else
        {
          playToneAndLight(yellValue);
          youLose();
        }
      }

//-----------------------------------------Blue Button------------------------------//
      if(sensorValue = analogRead(blueButt));  // read the analog in value:          
        // map it to the range of the analog out:
        outputValue = map(sensorValue, 0, 1023, 0, 255);
  
               // print the results to the serial monitor:
              Serial.println("sensor = " );                       
              Serial.println(sensorValue);   
 
       // wait 2 milliseconds before the next loop for the analog-to-digital converter to settle after the last reading:
      delay(2);   
  
  if (sensorValue <= 70)
  //(digitalRead(blueButt) == LOW)
      {  
        userSays = blueValue;
        if(userSays == simonSays[userStep])
        {
          playToneAndLight(blueValue);
          userStep++;
        }
        else
        {
          playToneAndLight(blueValue);
          youLose();
        }
      }
//-----------------------------------------Green Button------------------------------//
      if(sensorValue = analogRead(greenButt));  // read the analog in value:          
        // map it to the range of the analog out:
        outputValue = map(sensorValue, 0, 1023, 0, 255);
  
               // print the results to the serial monitor:
              Serial.println("sensor = " );                       
              Serial.println(sensorValue);   
 
       // wait 2 milliseconds before the next loop for the analog-to-digital converter to settle after the last reading:
      delay(2);   
  
  if (sensorValue <= 70)
     //(digitalRead(greenButt) == LOW)
      {  

        userSays = greenValue;
        if(userSays == simonSays[userStep])
        {
          playToneAndLight(greenValue);
          userStep++;
        }
        else
        {
          playToneAndLight(greenValue);
          youLose();
        }
      }
    }
    if (userStep >= nextStep)
    {
      simonDone = false;   // user completed successfully, give simon the next turn
    }
  }
}






