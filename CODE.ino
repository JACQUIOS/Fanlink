#include <SoftwareSerial.h>

// Define los pines de control para la velocidad del ventilador
const int ventiladorPin = 4;

// Inicializa el objeto de comunicación serial para Bluetooth
SoftwareSerial bluetoothSerial(10, 11); // RX, TX
char comando = ' ';
bool estado = false; // Variable para alternar entre 0 y 1
bool ventiladorEncendido = false; // Variable para rastrear el estado del ventilador

void setup() {
  // Inicializa la comunicación serial para la depuración
  Serial.begin(9600);
  // Inicializa la comunicación serial para Bluetooth
  bluetoothSerial.begin(9600);

  // Configura los pines de control para la velocidad como salidas
  pinMode(ventiladorPin, OUTPUT);
}

void loop() {
  // Espera comandos desde el dispositivo emparejado a través de Bluetooth
  if (bluetoothSerial.available() > 0) {
    Serial.println("CONECTADO");
    
    // Alterna el valor de estado y lo imprime
    estado = !estado;
    Serial.println(estado ? '1' : '0');

    // Lee el comando enviado desde el dispositivo Bluetooth
    comando = bluetoothSerial.read();
    // Imprime el comando recibido para depuración
    Serial.print("Comando recibido: ");
    Serial.println(comando);

    // Procesa los comandos recibidos
    if (comando == '1' || bluetoothSerial.available() > 0) {
      if (ventiladorEncendido) {
        apagarVentilador();
        ventiladorEncendido = false;
      } else {
        encenderVentilador();
        ventiladorEncendido = true;
      }
    } else if (comando == '0' || bluetoothSerial.available() > 0) {
      if (ventiladorEncendido) {
        apagarVentilador();
        ventiladorEncendido = false;
      } else {
        encenderVentilador();
        ventiladorEncendido = true;
      }
    }
  }
}

void encenderVentilador() {
  // Enciende el pin correspondiente a la velocidad baja del ventilador
  digitalWrite(ventiladorPin, HIGH);
  Serial.println("Ventilador encendido");
}

void apagarVentilador() {
  // Apaga todos los pines de control del ventilador
  digitalWrite(ventiladorPin, LOW);
  Serial.println("Ventilador apagado");
}
