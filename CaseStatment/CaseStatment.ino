
int ledPin = 9;      // LED connected to digital pin 9
int Pot = A3;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value
const int PhotoCell = A1;  // Analog input pin that the potentiometer is attached to
int speakerPin = 8;
int sensorValue = 0;        // value read from the pot
int outputValue = 0; 
int inputPin1 = 2;
int inputPin2 = 3;
int switchValue1 = 2;
int switchValue2 = 3;
int SwitchState1;
int SwitchState2;



void setup()
{
Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
pinMode(ledPin, OUTPUT);

}
void loop(){
int var;
SwitchState1 = digitalRead(switchValue1);
SwitchState2 = digitalRead(switchValue2);

if (SwitchState1 == LOW && SwitchState2 == HIGH){
  var = 1;
}

if (SwitchState1 == LOW && SwitchState2 == LOW){
  var = 2;
}

if ( SwitchState1 == HIGH && SwitchState2 == HIGH){
  var = 3;
}

if ( SwitchState1 == HIGH && SwitchState2 == LOW){
  var = 4;
}


switch (var){
  
  case 1:
  val = analogRead(Pot);   // read the input pin
  analogWrite(ledPin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  // read the analog in value:
  sensorValue = analogRead(PhotoCell);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
   // print the results to the serial monitor:
  Serial.println("sensor = " );                       
  Serial.println(sensorValue);   

    tone(8, 3000,2*sensorValue);
    delay(50);
    noTone(8);
    break;

case 2:
val = analogRead(Pot);   // read the input pin
  analogWrite(ledPin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  // read the analog in value:
  sensorValue = analogRead(PhotoCell);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
   // print the results to the serial monitor:
  Serial.println("sensor = " );                       
  Serial.println(sensorValue);   

    tone(8, sensorValue/2);
    delay(50);
    noTone(8);


break;

case 3:
val = analogRead(Pot);   // read the input pin
  analogWrite(ledPin, HIGH);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  delay(val);
  analogWrite(ledPin, LOW);
  delay(val);
  
  tone(8, 1000);
  delay(val*sensorValue);
  noTone(8);
  delay(val*sensorValue);
  // read the analog in value:
  sensorValue = analogRead(PhotoCell);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
   // print the results to the serial monitor:
  Serial.println("sensor = " );                       
  Serial.println(sensorValue);   

break;

case 4:
val = analogRead(Pot);   // read the input pin
  analogWrite(ledPin, HIGH);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  // read the analog in value:
  sensorValue = analogRead(PhotoCell);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
   // print the results to the serial monitor:
  Serial.println("sensor = " );                       
  Serial.println(sensorValue);   
  delay(sensorValue);
  analogWrite(ledPin, LOW);
  delay(sensorValue);
  
  tone(8, 1000);
  delay(sensorValue);
  noTone(8);
  delay(sensorValue);

break;

}
}
