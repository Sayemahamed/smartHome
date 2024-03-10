#include <Arduino.h>

// put function declarations here:
int data1 = 0, data2 = 0, data3 = 0;
bool light1 = false, light2 = false, fan = false, state = false;

void evaluate(int x, int y, int z)
{
  Serial.println(x);
  if (x == 111 and y == 110 and z != 101)
    state = true;
  if (x == 111 and y == 102 and z == 102)
    state = false;
  if (x == 111 and y == 110 and z == 101)
    light1 = state;
  else if (x == 49)
    light1 = state;
  if (x == 116 and y == 119 and z == 111)
    light2 = state;
  else if (x == 116 and y == 111)
    light2 = state;
  else if (x == 50)
    light2 = state;
  if (x == 102 and y == 97 and z == 110)
    fan = state;
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    data3 = data2;
    data2 = data1;
    data1 = Serial.read();
    evaluate(data3, data2, data1);
  }
  if (light1)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  if (light2)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
  if (fan)
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);
}
