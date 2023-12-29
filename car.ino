#include <SoftwareSerial.h>
//define tx2;
//define rx3;
SoftwareSerial BT(2,3);


const int trig_pin=8;
const int echo_pin=9;
int SPEED1=11; //오른쪽
int WHEEL1=10;
int SPEED2=6;//왼
int WHEEL2=5;
unsigned int val1= 150;
unsigned int val2= 150;

int led=4;


void setup() {
  
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(SPEED1,OUTPUT);
  pinMode(WHEEL1,OUTPUT);
  digitalWrite(WHEEL1,LOW);
  analogWrite(SPEED1,0);

  pinMode(SPEED2,OUTPUT);
  pinMode(WHEEL2,OUTPUT);
  digitalWrite(WHEEL2,LOW);
  analogWrite(SPEED2,0);

  pinMode(trig_pin,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(echo_pin,INPUT);
}

void loop() {
  char c =BT. read();

  
  if(BT.available())
  {
    Serial.write(BT.read());
  }
  if(Serial.available())
  {
    BT.write(Serial.read());
  }

  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);

  long duration=pulseIn(echo_pin ,HIGH);
  long distance=(duration/2)/29.1;

  
 if(distance<=20){

    
  Serial.println("warning");
  
  for(int i=0 ;i<=1;i++){
     analogWrite(SPEED2,0);
    digitalWrite(WHEEL2,LOW);
    analogWrite(SPEED1,0);
    digitalWrite(WHEEL1,LOW);
    
    if (i==0) {
    digitalWrite(led,i);
    delay(200);
    }
    else if(i==1){
    digitalWrite(led,i);
    delay(200);
       
    }
  }
  
 }
  else if (distance>20){

    if(c=='U'){
    digitalWrite(led,0);
    analogWrite(SPEED2,val2);
    digitalWrite(WHEEL2,LOW);
    analogWrite(SPEED1,val1);
    digitalWrite(WHEEL1,LOW);
    Serial.println("go");
    }

    else if(c=='D'){
    digitalWrite(led,0);
    analogWrite(SPEED2,val2);
    digitalWrite(WHEEL2,HIGH);
    analogWrite(SPEED1,val1);
    digitalWrite(WHEEL1,HIGH);
    Serial.println("back");
    }
    else if(c=='S'){
    digitalWrite(led,0);
    analogWrite(SPEED2,0);
    digitalWrite(WHEEL2,LOW);
    analogWrite(SPEED1,0);
    digitalWrite(WHEEL1,LOW);
    Serial.println("stop");
    }
  }
 }
  
