// Pinos dos reles 1-4 
#define rele1 11 //definido a pinagem
#define rele2 10  //definido a pinagem
#define rele3 9  //definido a pinagem
#define rele4 8  //definido a pinagem

int valordoblue;

// Pinos do potenciômetro digital X9C103
#define INC_PIN  2      // Pino de incremento (INC)
#define UD_PIN   3      // Pino de direção (U/D)
#define CS_PIN   4      // Pino de seleção de chip (CS)

int valor = 0;  // Valor inicial


void setup()

{
  // Iniciar a Serial
  Serial.begin(9600); //Início da serial do bluetooth

 // Pinos dos reles 1-4 
  pinMode(rele1, OUTPUT); //Ligando a saída dos reles
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  digitalWrite(rele1,HIGH); //Garantir que os reles estejam desligados antes do comando
  digitalWrite(rele2,HIGH);
  digitalWrite(rele3,HIGH);
  digitalWrite(rele4,HIGH);

// Pinos do potenciômetro digital X9C103
  pinMode(INC_PIN, OUTPUT);
  pinMode(UD_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(UD_PIN, HIGH);
  digitalWrite(CS_PIN, LOW);
  
  // Incrementar o valor inicial
  for (int i = 0; i < valor; i++) {
    digitalWrite(INC_PIN, HIGH);
    delay(10);
    digitalWrite(INC_PIN, LOW);
    delay(10);
  }
 // Deselecionar o chip    
  digitalWrite(CS_PIN, HIGH);
}

void loop() {

  // Funcionamento dos reles
  if (Serial.available()>0) //Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
  {
  valordoblue = Serial.read();
  }

// Funcionamento do X9C103 
  // Incrementar ou decrementar o valor com base na entrada serial
  if (Serial.available()) {
    char entrada = Serial.read();

    if (entrada == 'i' || entrada == 'I') {
      incrementar();
    } else if (entrada == 'S' || entrada == 's') {
      decrementar();
    }
  }

// Funcionamento dos reles
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

// Funcionamento do X9C103
void incrementar() {
  digitalWrite(UD_PIN, HIGH);  // Configurar para incremento

  // Selecionar o chip
  digitalWrite(CS_PIN, LOW);

  // Incrementar o valor
  digitalWrite(INC_PIN, HIGH);
  delay(10);
  digitalWrite(INC_PIN, LOW);
  delay(10);

  // Deselecionar o chip
  digitalWrite(CS_PIN, HIGH);

  valor += 100;  // Atualizar o valor
}

void decrementar() {
  digitalWrite(UD_PIN, LOW);  // Configurar para decremento

  // Selecionar o chip
  digitalWrite(CS_PIN, LOW);

  // Decrementar o valor
  digitalWrite(INC_PIN, HIGH);
  delay(10);
  digitalWrite(INC_PIN, LOW);
  delay(10);
 
  // Deselecionar o chip
  digitalWrite(CS_PIN, HIGH);

  valor -= 100;  // Atualizar o valor
}
