// Definición de pines
int buzzer = 12;  // Pin digital conectado al buzzer
int analogPin = A0;  // Pin analógico conectado al sensor de monóxido de carbono (o cualquier sensor analógico)
String alarm = "e"; // e de encendido

// Configuración inicial
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 bps
  pinMode(buzzer, OUTPUT); // Configura el pin del buzzer como salida
}

// Bucle principal
void loop() {
  int val;
  val = analogRead(analogPin);  // Lee el valor del sensor conectado al pin A0
  Serial.println(val, DEC); // Imprime el valor leído en el monitor serial en formato decimal

  // Si el valor leído del sensor es mayor a 600, se activa la alarma
  if (val > 0) {
    unsigned char i;

    // Bucle infinito para activar el buzzer mientras el valor del sensor siga siendo alto
    while (alarm == "e") {
      // Verifica si hay un comando enviado desde Processing
      if (Serial.available() > 0) {
        char comando = Serial.read();
        if (comando == 'a') {
          alarm = "d"; // Cambia el estado de la alarma para detener el buzzer
        }
      }

      // Si la alarma sigue encendida, sigue sonando el buzzer
      if (alarm == "e") {
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
          delay(2);  // Espera 3 ms
          digitalWrite(buzzer, LOW);  // Desactiva el buzzer
          delay(2);  // Espera 3 ms
        }
      }
    }
  }

  delay(100);  // Espera 100 ms antes de la siguiente lectura del sensor
}
