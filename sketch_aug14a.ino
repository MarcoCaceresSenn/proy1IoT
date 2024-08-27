// Definición de pines
int buzzer = 12;  // Pin digital conectado al buzzer
int analogPin = A0;  // Pin analógico conectado al sensor de monóxido de carbono (o cualquier sensor analógico)

// Configuración inicial
void setup()
{
  Serial.begin(9600); // Inicia la comunicación serial a 9600 bps
  pinMode(buzzer, OUTPUT); // Configura el pin del buzzer como salida
}

// Bucle principal
void loop()
{
  int val;
  val = analogRead(analogPin);  // Lee el valor del sensor conectado al pin A0
  Serial.println(val, DEC); // Imprime el valor leído en el monitor serial en formato decimal

  // Si el valor leído del sensor es mayor a 600, se activa la alarma
  if (val > 600) {
    unsigned char i;

    // Bucle infinito para activar el buzzer mientras el valor del sensor siga siendo alto
    while (1) {
      // Genera un sonido rápido en el buzzer
      for (i = 0; i < 80; i++) {
        digitalWrite(buzzer, HIGH);  // Activa el buzzer
        delay(1);  // Espera 1 ms
        digitalWrite(buzzer, LOW);  // Desactiva el buzzer
        delay(1);  // Espera 1 ms
      }

      // Genera un sonido más lento en el buzzer
      for (i = 0; i < 100; i++) {
        digitalWrite(buzzer, HIGH);  // Activa el buzzer
        delay(2);  // Espera 2 ms
        digitalWrite(buzzer, LOW);  // Desactiva el buzzer
        delay(2);  // Espera 2 ms
      }
    }
  }

  delay(100);  // Espera 100 ms antes de la siguiente lectura del sensor
}
