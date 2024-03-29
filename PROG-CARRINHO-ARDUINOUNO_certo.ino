﻿/* DEFINIÇÃO GERAL:

* Entradas:
botões serial (Bluetooth)

* Saídas: 
MotorA
MotorB 

*/

// * * * * * MOVIMENTAÇÃO DO CARRINHO:
#define motorA1 8 // Sent. horário - IN1
 
#define motorA2 9 // Senti.Anti-horário - IN2

#define motorB1 10 // Sent. horário - IN3

#define motorB2 11 // Senti.Anti-horário - IN4

char teclas;
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void setup() {
    
 // * * * * * MOVIMENTAÇÃO DO CARRINHO:   
 pinMode(motorA1, OUTPUT); 
 pinMode(motorA2, OUTPUT);
 pinMode(motorB1, OUTPUT);
 pinMode(motorB2, OUTPUT);
 digitalWrite(motorA1, LOW);
 digitalWrite(motorA2, LOW);
 digitalWrite(motorB1, LOW);
 digitalWrite(motorB2, LOW);
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

  // Inicializar a Serial
  Serial.begin(9600);
 
}

void loop() {
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
  // Verificar se a Serial está disponível
  if (Serial.available()>0)
   {
   teclas = Serial.read();
   }

// * * * * * MOVIMENTAÇÃO DO CARRINHO: 
  if (teclas == 'F')   // IN2 e IN4 = FRENTE
 {
  frente();
 }
 
  else if (teclas == 'L')   // IN1 = FRENTE esquerda
 {
  esquerda();
 }
  
  else if (teclas == 'R')   // IN3 = FRENTE direita
 {
  direita();
 }

  else if (teclas == 'B')    // IN2 e IN4 = TRÁS
 {
  atras();
 }
  else  if (teclas == 'S') // SENAO DESLIGA TUDO
 {
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB2,LOW);
  digitalWrite(motorA1,LOW);
  digitalWrite(motorB1,LOW);
  // DESLIGAR TUDO
 }
}
  
//} - __TALVEZ__ PRECISE DE ALGUMA CHAVE NESSA PARTE DO PROGRAMA.
//}

// * * * * * MOVIMENTAÇÃO DO CARRINHO:
void frente(){  
   digitalWrite(motorA1,HIGH);
   digitalWrite(motorB1,HIGH);
   digitalWrite(motorA2,LOW);
   digitalWrite(motorB2,LOW);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void esquerda(){
   digitalWrite(motorA1,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorA2,LOW);
   digitalWrite(motorB2,HIGH);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void direita(){
   digitalWrite(motorA1,LOW);
   digitalWrite(motorB1,HIGH);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB2,LOW);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void atras(){
     
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB2,HIGH);
   digitalWrite(motorA1,LOW);
   digitalWrite(motorB1,LOW);
}
