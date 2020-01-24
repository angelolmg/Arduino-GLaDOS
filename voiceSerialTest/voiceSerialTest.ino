// define pin numbers
#include <Servo.h>

#define SERVO 9 // Porta Digital 6 PWM
Servo s; // Variável Servo
int pos; // Posição Servo
int servoDelay = 30;
int lightDelay = 15;
int moveChance = 50;

#define BLUE 3
#define GREEN 5
#define RED 6

// define variables
int redValue;
int greenValue;
int blueValue;

void setup() {
s.attach(SERVO);
s.write(115); // Inicia motor posição zero

pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);

Serial.begin(9600); // Starts the serial communication
}

void loop() {
  if(Serial.available() > 0){
    int input = Serial.read();
    switch (input) {
    case '1':                         
      digitalWrite(RED, HIGH);
      moveServo();
      break;
    case '2':                         
      digitalWrite(RED, LOW);
      moveServo();
      break;
    case '3':
      digitalWrite(GREEN, HIGH);
      moveServo();
      break;
    case '4':                         
      digitalWrite(GREEN, LOW);
      moveServo();
      break;
    case '5':                         
      digitalWrite(BLUE, HIGH);
      moveServo();
      break;
    case '6':
      digitalWrite(BLUE, LOW);
      moveServo();
      break;
    default:
      break;
    }
  }
}

void moveServo()
{
  //delay(1500);
  int minNum = random(100, 130);
  int maxNum = random(100, 130);

  while(maxNum <= minNum){
    maxNum = random(100, 130);
  }
   
  for(pos = minNum; pos < maxNum; pos++)
  {
    s.write(pos);
    delay(servoDelay);
  }
  delay(100);
  for(pos = maxNum; pos >= minNum; pos--)
  {
    s.write(pos);
    delay(servoDelay);
  } 
}

void moveDown() {
  s.write(140);
}

void moveMiddle() {
  s.write(115);
}

void moveUp() {
  s.write(90);
}

void playLights()
{
  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;
  
  // this is unnecessary as we've either turned on RED in SETUP
  // or in the previous loop ... regardless, this turns RED off
  // analogWrite(RED, 0);
  // delay(1000);
  
  for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
  redValue -= 1;
  greenValue += 1;
  // The following was reversed, counting in the wrong directions
  // analogWrite(RED, 255 - redValue);
  // analogWrite(GREEN, 255 - greenValue);
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  delay(lightDelay);
  }
  
  redValue = 0;
  greenValue = 255;
  blueValue = 0;
  
  for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
  greenValue -= 1;
  blueValue += 1;
  // The following was reversed, counting in the wrong directions
  // analogWrite(GREEN, 255 - greenValue);
  // analogWrite(BLUE, 255 - blueValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  delay(lightDelay);
  }
  
  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  
  for(int i = 0; i < 255; i += 1) // fades out blue bring green full when i=255
  {
  // The following code has been rearranged to match the other two similar sections
  blueValue -= 1;
  redValue += 1;
  // The following was reversed, counting in the wrong directions
  // analogWrite(BLUE, 255 - blueValue);
  // analogWrite(RED, 255 - redValue);
  analogWrite(BLUE, blueValue);
  analogWrite(RED, redValue);
  delay(lightDelay);
  }
}
