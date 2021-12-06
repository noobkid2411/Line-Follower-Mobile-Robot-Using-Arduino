int motorRight = 9; // Right motor connected to PWM pin 9
int motorLeft = 10; // Left motor connected to PWM pin 10

int rightEye = 5; // Right IR sensor connected to digital pin 5
int leftEye = 6; // Left IR sensor connected to digital pin 6

int left = 0; // Initialize variable 'left'
int right = 0; // Initialize variable 'right'

void setup()
{
  pinMode(motorRight,OUTPUT); // setting the PWM pin 9 as output
  pinMode(motorLeft,OUTPUT); // setting the PWM pin 10 as output

  pinMode(rightEye,INPUT); // setting the digital pin 5 as input
  pinMode(leftEye,INPUT); // setting the digital pin 6 as input

  digitalWrite(rightEye,LOW); // sets the right IR sensor to low (or 0)
  digitalWrite(leftEye,LOW); // sets the left IR sensor to low (or 0)
}

void loop()
{
  analogWrite(motorRight,255); // sets right motor to analog value 255 (max rpm)
  analogWrite(motorLeft,255); // sets left motor to analog value 255 (max rpm)

  right = digitalRead(rightEye); // reads value from right IR sensor and assigns it to the variable 'right'
  left = digitalRead(leftEye); // reads value from left IR sensor and assigns it to the variable 'left'
  

  if(right==1 && left==0) // When right PIR sensor detects the black line, right motor is stopped while left motor continues to rotate. 
      // This produces a turning effect and the bot turns to the right.
  {    
    analogWrite(motorRight,0); // right motor set to 0 (min rpm)
    analogWrite(motorLeft,255); // left motor set to 255 (max rpm)
  }
  
  
  if(left==1 && right==0)  // When left PIR sensor detects the black line, left motor is stopped while right motor continues to rotate. 
      // This produces a turning effect and the bot turns to the left.
  {
      analogWrite(motorLeft,0); // left motor set to 0 (min rpm)
      analogWrite(motorRight,255); // right motor set to 255 (max rpm)
  }


  if(left==1 && right==1) // When both PIR sensors detect the black line, both motors are stopped due to which the bot comes to rest.
  {
    analogWrite(motorRight,0); // right motor set to 0 (min rpm)
    analogWrite(motorLeft,0); // left motor set to 0 (min rpm)
  }
    
}
