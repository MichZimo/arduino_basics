//www.elegoo.com
//2016.12.08
/*****************************************/
const int ballSwitch = 2;
const int ledBlue = 3;
const int ledGreen = 5;
const int ledRed = 6;
int redValue = 255;
int greenValue = 0;
int blueValue = 0;
const int delayTime = 10;

void setup()
{ 
  //initialize the ledPin as an output
  pinMode(ledBlue,OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ballSwitch,INPUT);
  digitalWrite(ballSwitch, HIGH);
  Serial.begin(9600);
} 
/******************************************/
void loop() 
{  
  int digitalVal = digitalRead(ballSwitch);
  if(HIGH == digitalVal)
  {
    Serial.println("No Connection");
    for(int i = 0; i < 255; i += 1)
    {
      redValue -= 1;
      greenValue += 1;
      blueValue += 2;

      analogWrite(ledRed, redValue);
      analogWrite(ledBlue, blueValue);
      analogWrite(ledGreen, greenValue);
      delay(delayTime);
    }
  }
  else
  {
    Serial.println("Connection"); 
    analogWrite(ledRed, 0);
    analogWrite(ledBlue, 0);
    analogWrite(ledGreen, 0);
  }
}
/**********************************************/

