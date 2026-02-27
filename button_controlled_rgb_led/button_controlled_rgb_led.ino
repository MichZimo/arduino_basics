// Define pins
// RGB LED
int BLUE = 11;
int GREEN = 10;
int RED = 9;

// RGB buttons
int buttonBlue = 4;
int buttonRed = 3;
int buttonGreen = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(buttonBlue, INPUT_PULLUP);
  pinMode(buttonGreen, INPUT_PULLUP);
  pinMode(buttonRed, INPUT_PULLUP);
}

void loop() 
{
  
  // Blue light
  if (digitalRead(buttonBlue) == LOW)
  {
    Serial.print("Blue Button pushed");
    delay(10);
    analogWrite(BLUE, 255);
    Serial.print("Signal sent to blue");
    delay(1000);
  } else {
    analogWrite(BLUE, 0);
  }
  
  if (digitalRead(buttonGreen) == LOW || digitalRead(buttonRed) == LOW) 
  {
    delay(100);
    if (digitalRead(buttonGreen) == LOW && digitalRead(buttonRed) == LOW)
    { 
      analogWrite(GREEN, 100);
      analogWrite(RED, 90);
      delay(1000);
      } else if (digitalRead(buttonRed) == LOW)
    {
      analogWrite(RED, 255);
      delay(1000);
    } else if (digitalRead(buttonGreen) == LOW)
    {
      analogWrite(GREEN, 255);
      delay(1000);
      } 
  //delay(1000);
 } else {
  analogWrite(GREEN, 0);
  analogWrite(RED, 0);
 }
}
