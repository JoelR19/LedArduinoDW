#include <Servo.h>

Servo servo_7; // Crea un objeto Servo

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  pinMode(13, OUTPUT); // Configura el pin del LED como salida
  servo_7.attach(9); // Asocia el objeto Servo al pin 9
}

void loop() {
  if (Serial.available() > 0) { // Verifica si hay datos disponibles para leer
    char command = Serial.read(); // Lee el comando enviado desde el puerto serial
    if (command == '1') { // Si el comando es '1'
      servo_7.write(90); // Mueve el servo a 90 grados
      delay(500); // Espera 500 milisegundos
      digitalWrite(13, HIGH); // Enciende el LED
    } else if (command == '0') { // Si el comando es '0'
      delay(500); // Espera 500 milisegundos
      servo_7.write(0); // Mueve el servo a 0 grados
      digitalWrite(13, LOW); // Apaga el LED
    }
  }
}
