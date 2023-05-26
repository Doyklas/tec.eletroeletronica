#include <SoftwareSerial.h>

#define UD  2
#define INC 3
#define CS  4

char b1;
char b2;

SoftwareSerial mySerial(0,1); 
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);

  Serial.begin(9600);
  pinMode(INC, OUTPUT);
  pinMode(UD, OUTPUT);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
}

void loop() {
  
  b1 = mySerial.read();
  delay(300);

  if(b1 == 'G'){
    digitalWrite(12,HIGH);
    delay(300);
    digitalWrite(13,HIGH);
    delay(300);
    }
    if(b1 == 'R'){
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(12,HIGH);
    delay(300);
    }
    if(b1 == 'D'){
    digitalWrite(9,HIGH);
    delay(300);
    }
    if(b1 == 'A'){
    digitalWrite(9,LOW);
    delay(300);
    }
     if(b1 == 'F'){
    digitalWrite(8,HIGH);
    delay(300);
    }
     if(b1 == 'T'){
    digitalWrite(8,LOW);
    delay(300);
    }
    if(b1 == '0'){
      down();
      }
    if(b1 == '1'){
      up();
      }
}
void up(){
    digitalWrite(UD, HIGH);
    digitalWrite(INC, HIGH);
    digitalWrite(CS, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
    digitalWrite(INC, LOW);
    digitalWrite(CS, HIGH);
            
}
void down(){
    digitalWrite(UD, LOW);
    digitalWrite(INC, HIGH);
    digitalWrite(CS, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
    digitalWrite(CS, HIGH);
            
}

      



      
