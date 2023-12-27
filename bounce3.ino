
#include <Bounce2.h>
int led1=13;
int led2=12;
int button1 =2;
int button2=4;
Bounce debouncer1= Bounce();
Bounce debouncer2= Bounce();
void setup(){
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
  pinMode(button1,INPUT_PULLUP);
   pinMode(button2,INPUT_PULLUP);
  debouncer1.attach(button1);
  debouncer2.attach(button2);
  debouncer1.interval(5);
  debouncer2.interval(5);
  Serial.begin(9600);
  
}

void loop() {
debouncer1.update();
debouncer2.update();
if(debouncer1.fell()){
  for(int i=0;i<=1;i++){
  Serial.println("R PRESS");
  digitalWrite( led2,HIGH);
  
  }
  }
  
if(debouncer1.rose()){
 
  Serial.println("R released");
  digitalWrite( led2,LOW);
}


if(debouncer2.fell()){
  Serial.println("L PRESS");
  digitalWrite( led1,HIGH);
}
if(debouncer2.rose()){
  Serial.println("L released");
  digitalWrite( led1,LOW);
}
}
