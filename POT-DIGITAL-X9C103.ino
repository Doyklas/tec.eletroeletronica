// Pinos do potenciômetro digital X9C103
#define INC_PIN  2      // Pino de incremento (INC)
#define UD_PIN   3      // Pino de direção (U/D)
#define CS_PIN   4      // Pino de seleção de chip (CS)

int valor = 0;  // Valor inicial

void setup() {
  pinMode(INC_PIN, OUTPUT);
  pinMode(UD_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);

  // Configurar o potenciômetro para incrementar
  digitalWrite(UD_PIN, HIGH);

  // Selecionar o chip
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

  Serial.begin(9600);  // Inicializar a comunicação serial
}

void loop() {
  // Ler o valor do potenciômetro
  Serial.print("Valor atual: ");
  Serial.println(valor);

  // Incrementar ou decrementar o valor com base na entrada serial
  if (Serial.available()) {
    char entrada = Serial.read();

    if (entrada == 'i' || entrada == 'I') {
      incrementar();
    } else if (entrada == 'd' || entrada == 'D') {
      decrementar();
    }
  }
}

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
