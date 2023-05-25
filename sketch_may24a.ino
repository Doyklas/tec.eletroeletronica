/* 
Conectividade c/ Bluetooth:
Hardware(HW)
Módulo Bluetooth (HC-05)
f=2,4GHz (Rf - Antena)
*/

#define RL1 10
#define RL2 2
#define RL3 3
#define RL4 4

char teclas = 0; 

void setup()
{
  // Definir relés como saída 
  pinMode(RL1,OUTPUT);
  pinMode(RL2,OUTPUT);
  pinMode(RL3,OUTPUT);
  pinMode(RL4,OUTPUT);

  // Inicializar a Serial
  Serial.begin(9600);

  // Definir relés ligados ou desligados logo de início
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,HIGH);
  digitalWrite(RL3,HIGH);
  digitalWrite(RL4,HIGH);
}

void loop()
{ 
  
  // Verificar se a Serial está disponível
  if (Serial.available()>0)
  {
  teclas = Serial.read();
  }

  //************************************************************
  // Comando de ligar - RELÉ 1
  if(teclas == 'A')
  {
    digitalWrite(RL1,LOW);
  }
  else if (teclas == 'a')
  {
   digitalWrite(RL1,HIGH);
  }
  //************************************************************
  // Comando de desligar - RELÉ 2
  if(teclas == 'B')
  {
   digitalWrite(RL2,LOW); 
  }
    else if (teclas == 'b')
  {
   digitalWrite(RL2,HIGH);
  }
  //************************************************************  
   // Comando de sentido anti-horário - RELÉ 3
  if(teclas == 'C')
  {
   digitalWrite(RL3,LOW); 
  }
    else if (teclas == 'c')
  {
   digitalWrite(RL3,HIGH);
  }
   //************************************************************ 
   // Comando de seleção (potenciomêtro digital ou analógico) - RELÉ 4
  if(teclas == 'D')
  {
   digitalWrite(RL4,LOW); 
  }
    else if (teclas == 'd')
  {
   digitalWrite(RL4,HIGH);
  }
   //************************************************************
}
