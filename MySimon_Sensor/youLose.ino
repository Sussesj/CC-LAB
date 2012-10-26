void youLose(){
        
        // Play a Shameful Sound
        tone(speakerPin,1000);
        delay(400);
        tone(speakerPin,500);
        delay(400);
        tone(speakerPin,1000);
        delay(400);
        tone(speakerPin,500);
        delay(600);
        tone(speakerPin,100);
        delay(1500);
        tone(speakerPin,50);
        delay(1500);
        
        noTone(speakerPin);
        
        //  Reset Program To Start Fresh
        nextStep = 0;
        userStep = 0;
        simonSpeed = 400;
        simonDone = false;
          
          delay(1500);
        restartSeq();
      
        delay(1500);
        
  }
  
 
void restartSeq(){
  
    tone(speakerPin,800);
    delay(100);
    digitalWrite(redLED,HIGH);
    digitalWrite(yellLED,HIGH);
    digitalWrite(blueLED,HIGH);
    digitalWrite(greenLED,HIGH);
    tone(speakerPin,850);
    delay(100);
    
    digitalWrite(redLED,LOW);
    tone(speakerPin,1000);
    delay(400);
    
    digitalWrite(yellLED,LOW);
    tone(speakerPin,2000);
    delay(300);
    
    
    digitalWrite(blueLED,LOW);
    tone(speakerPin,3000);
    delay(250);
    
    digitalWrite(greenLED,LOW);
    tone(speakerPin,4000);
    delay(200);
    
    noTone(speakerPin);
    
    }

    
 
    
