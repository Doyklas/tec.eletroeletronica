#define rele1 10 //definido a pinagem
#define rele2 2  //definido a pinagem
#define rele3 3  //definido a pinagem
#define rele4 4  //definido a pinagem

int valordoblue;

void setup()

{
  Serial.begin(9600); //Início da serial do bluetooth
  pinMode(rele1, OUTPUT); //Ligando a saída dos reles
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  digitalWrite(rele1,HIGH); //Garantir que os reles estejam desligados antes do comando
  digitalWrite(rele2,HIGH);
  digitalWrite(rele3,HIGH);
  digitalWrite(rele4,HIGH);

}

void loop() {
  if (Serial.available()>0) //Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
  {
  valordoblue = Serial.read();
  }




 if (valordoblue=='A') //Leitura dos valores para saber se deve acender ou não o LED
 {
  digitalWrite (rele1,HIGH);
  }

    if (valordoblue=='a')
 {
  digitalWrite (rele1,LOW);
  }





    if (valordoblue=='B')
 {
  digitalWrite (rele2,HIGH);
  }

    if (valordoblue=='b')
 {
  digitalWrite (rele2,LOW);
 }





 if (valordoblue=='C')
 {
  digitalWrite (rele3,HIGH);
  }

    if (valordoblue=='c')
 {
  digitalWrite (rele3,LOW);
  }




 if (valordoblue=='D')
 {
  digitalWrite (rele4,HIGH);
  }

    if (valordoblue=='d')
 {
  digitalWrite (rele4,LOW);
  }

  Serial.print(valordoblue);


}
