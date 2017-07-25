// Set Motor Control Pins
int rightMotor2 = 13;    // D7 - right Motor -
int rightMotor1 = 15;    // D8 - right Motor +
int leftMotor2 = 0;    // D3 - left Motor - 
int leftMotor1 = 2;    // D4 - left Motor +
int eneLeftMotor = 12;  // D6 - enable Mortor Left
int eneRightMotor = 14; // D5 - enable Mortor Right
int buttonPin = 16; // D0
void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(eneLeftMotor, OUTPUT); 
  pinMode(eneRightMotor, OUTPUT); 
  pinMode(leftMotor1, OUTPUT); 
  pinMode(leftMotor2, OUTPUT);  
  pinMode(rightMotor1, OUTPUT);  
  pinMode(rightMotor2, OUTPUT);  
  digitalWrite(eneLeftMotor,LOW);
  digitalWrite(eneRightMotor,LOW);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
      
  while (digitalRead(buttonPin))  // Wait for button to be pressed to move on 
  {  
  }
}
void loop()
{
  forwardMotor();
  delay (5000);
  stopMotor();
  delay (200);
  leftMotor();
  delay (3000);
  stopMotor();
  delay (200);
  forwardMotor();
  delay (5000);
  stopMotor();
  delay (200);
  rightMotor();
  delay (3000);
  stopMotor();
  delay (200);
  reverseMotor();
  delay (5000);
  stopMotor();
  delay (200);
} 
/* command motor forward */
void forwardMotor(void)   
{
  digitalWrite(eneLeftMotor,HIGH);
  digitalWrite(eneRightMotor,HIGH);
    
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}
/* command motor backward */
void reverseMotor(void)   
{
  digitalWrite(eneLeftMotor,HIGH);
  digitalWrite(eneRightMotor,HIGH);
  
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
}
/* command motor turn left */
void leftMotor(void)   
{
  digitalWrite(eneLeftMotor,HIGH);
  digitalWrite(eneRightMotor,HIGH); 
  
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}
/* command motor turn right */
void rightMotor(void)   
{
  digitalWrite(eneLeftMotor,HIGH);
  digitalWrite(eneRightMotor,HIGH);
  
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
}
/* command motor stop */
void stopMotor(void)   
{
  digitalWrite(eneLeftMotor,LOW);
  digitalWrite(eneRightMotor,LOW);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
}

