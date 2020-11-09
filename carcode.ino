#include <MemoryFree.h>
#include <EEPROM.h>
#define dirA 12
#define dirB 13
#define pwmA 3
#define pwmB 11
#define breakA 9
#define breakB 10

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(breakA, OUTPUT);
  pinMode(breakB, OUTPUT);
}
int x, y;
byte mess[2];
void loop() {
  if (Serial3.available()>1) {
    Serial3.readBytes(mess, 2);

    x = int(mess[0])-100;
    y = int(mess[1])-100;

    go('a', y + x); //left motor
    go('b', y - x); //right motor

  analogWrite(breakA, 0);
  analogWrite(breakB, 0);
  }
}

void go(char motor, int velocity) {
  int motorSpeed;

  if(velocity > 0)
  {
    motorSpeed = map(velocity, 0, 100, 0, 255);
    if (motor == 'a') 
    {
      digitalWrite(dirA, HIGH);
      analogWrite(pwmA, motorSpeed);
    }
    else if (motor == 'b') 
    {
      digitalWrite(dirB, HIGH);
      analogWrite(pwmB, motorSpeed);
    }
  }

  else if (velocity < 0) 
  {
    motorSpeed = map(-velocity, 0, 100, 0, 255);
    if (motor == 'a') 
    {
      digitalWrite(dirA, LOW);
      analogWrite(pwmA, motorSpeed);
    }
    else if (motor == 'b') 
    {
      digitalWrite(dirB, LOW);
      analogWrite(pwmB, motorSpeed);
    }
  }

  else 
  {
    if (motor == 'a') 
    {
      analogWrite(pwmA, 0);
    }
    else if (motor == 'b') 
    {
      analogWrite(pwmB, 0);
    }
  }
}
