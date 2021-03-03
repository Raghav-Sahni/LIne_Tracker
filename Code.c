/*
  ELEC1100 Project Template

  To program the car tracking the white line on a dark mat

  Your Name: Raghav Sahni                
  Student ID: 20730285

*/

// assign meaningful names to those pins that will be used

#define pinLeftSensor A5      //pin A5
#define pinRightSensor A3     //pin A3
#define pinMiddleSensor A4    //pin A4

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

#define pinPWM_L 10            //pin D10
#define pinPWM_R 9          //pin D9

// define YOUR OWN variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int middleSensor = 1;
int count = 0;
int flag =0;

// the setup function runs once when you press reset or power the board
void setup ()
{
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMiddleSensor, INPUT);
  
  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);
  
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);  
  
  // initialize output pins.
  digitalWrite(pinLdir, HIGH);        
  digitalWrite(pinRdir, HIGH);   

  // initialize PWM.
  analogWrite(pinPWM_L, 200);
  analogWrite(pinPWM_R, 200);
  delay(3000);
  
}

// the loop function runs over and over again forever
void loop()
{
    leftSensor = digitalRead(pinLeftSensor);
    rightSensor = digitalRead(pinRightSensor);
    middleSensor = digitalRead(pinMiddleSensor);
 switch(count) {
   case 0:   digitalWrite(pinLdir, LOW);        
             digitalWrite(pinRdir, LOW);   
             analogWrite(pinPWM_R, 0);
             analogWrite(pinPWM_L, 0);
             if (!middleSensor) {
              count = 1;
               analogWrite(pinPWM_L, 200);
               analogWrite(pinPWM_R, 200);
             }
             break;
    
    case 1:  if ( leftSensor && rightSensor ) {
               digitalWrite(pinLdir, HIGH);
               digitalWrite(pinRdir, HIGH);
              }

             if ( !leftSensor && rightSensor ) {
               digitalWrite(pinLdir, LOW);
               digitalWrite(pinRdir, HIGH);
               analogWrite(pinPWM_L, 150);
              }

             if ( leftSensor && !rightSensor ) {
               digitalWrite(pinLdir, HIGH);
               digitalWrite(pinRdir, LOW);
               analogWrite(pinPWM_R, 150);
             }

             if ( !leftSensor && !rightSensor ) {
                 digitalWrite(pinLdir, HIGH);
                 digitalWrite(pinRdir, HIGH);
               flag = 1;
             }
             else if (flag ==1)
               count = 2;
             break;
     case 2: if ( leftSensor && rightSensor ) {
               digitalWrite(pinLdir, HIGH);
               digitalWrite(pinRdir, HIGH);
              }

             if ( !leftSensor && rightSensor ) {
               digitalWrite(pinLdir, LOW);
               digitalWrite(pinRdir, HIGH);
               analogWrite(pinPWM_L, 150);
              }

             if ( leftSensor && !rightSensor ) {
               digitalWrite(pinLdir, HIGH);
               digitalWrite(pinRdir, LOW);
               analogWrite(pinPWM_R, 150);
             }

              if ( !leftSensor && !rightSensor ) {
                 digitalWrite(pinLdir, LOW);
                 digitalWrite(pinRdir, HIGH);
                 analogWrite(pinPWM_L, 150);
                 flag = 2;
             }
              else if (flag ==2)
               count = 2;
              if (!middleSensor) {
               digitalWrite(pinLdir, LOW);
               digitalWrite(pinRdir, LOW);
                count = 3;
             }
             break;
     case 3:digitalWrite(pinLdir, LOW);
            digitalWrite(pinRdir, LOW);
            if ( leftSensor && !rightSensor ) {
              analogWrite(pinPWM_L, 0);
              analogWrite(pinPWM_R, 0);
             }
  }
 
}