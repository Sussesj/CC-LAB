// Using an animal to make sound - next it to incorporate a fotosensor!

int ledPin = 9;    
int ledPin2 = 10;
int delayPeriod = 250;
void setup()  { 
  Serial.begin(1115200);
  pinMode(2,OUTPUT);
 
} 
//when the psycedelic animal wakes up
void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect                              
  } 
  for(int y=0; y<6000;y+=5)
  {
    Serial.print("y+=5");
    Serial.print(" Freq: ");
    Serial.println(y);

    tone(2, y);
    delay(5); //play with delay "ratio"
    noTone(2);
    delay(1); //play with delay "ratio"
  }

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);                                    
  } 
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin2, fadeValue);                                    
  } 
  for(int y=0; y<6000;y+=5)
  {
    Serial.print("y-=5");
    Serial.print(" Freq: ");
    Serial.println(y);

    tone(2, y);
    delay(5); //play with delay "ratio"
    noTone(2);
    delay(1); //play with delay "ratio"
  }

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin2, fadeValue);                                   
  } 

  //when animal is alive - when the eyes pop out
  for (int i = 0; i < 20; i ++)
  { 
    digitalWrite(ledPin,HIGH);
    digitalWrite(ledPin2,HIGH);
    tone(2, 440, 200);
    delay(delayPeriod);
    digitalWrite(ledPin,LOW);
    digitalWrite(ledPin2,LOW);
    tone(2, 494, 500);
    delay(delayPeriod);
  }

  delay(5*delayPeriod);

}



