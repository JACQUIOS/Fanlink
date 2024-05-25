#include <SoftwareSerial.h>

// Define los pines de control para la velocidad del ventilador
const int velocidadBajaPin = 2;
const int velocidadMediaPin = 3;
const int velocidadAltaPin = 4;

// Inicializa el objeto de comunicación serial para Bluetooth
SoftwareSerial bluetoothSerial(10, 11); // RX, TX

void setup() {
  // Inicializa la comunicación serial para la depuración
  Serial.begin(9600);
  // Inicializa la comunicación serial para Bluetooth
  bluetoothSerial.begin(9600);

  // Configura los pines de control para la velocidad como salidas
  pinMode(velocidadBajaPin, OUTPUT);
  pinMode(velocidadMediaPin, OUTPUT);
  pinMode(velocidadAltaPin, OUTPUT);
}

void loop() {
  // Espera comandos desde el dispositivo emparejado a través de Bluetooth
  if (bluetoothSerial.available() > 0) {
     Serial.println("CONECTADO");
    // Lee el comando enviado desde el dispositivo Bluetooth
    String comando = bluetoothSerial.readString();
    // Imprime el comando recibido para depuración
    Serial.println("Comando recibido: " + comando);

    // Procesa los comandos recibidos
    if (comando == "encender") {
      encenderVentilador();
    } else if (comando == "apagar") {
      apagarVentilador();
    } else if (comando == "velocidad baja") {
      ajustarVelocidad(1);
    } else if (comando == "velocidad media") {
      ajustarVelocidad(2);
    } else if (comando == "velocidad alta") {
      ajustarVelocidad(3);
    }
  }
}

void encenderVentilador() {
  // Enciende el pin correspondiente a la velocidad baja del ventilador
  digitalWrite(velocidadBajaPin, HIGH);
}

void apagarVentilador() {
  // Apaga todos los pines de control del ventilador
  digitalWrite(velocidadBajaPin, LOW);
  digitalWrite(velocidadMediaPin, LOW);
  digitalWrite(velocidadAltaPin, LOW);
}

void ajustarVelocidad(int velocidad) {
  // Apaga todos los pines de control del ventilador
  apagarVentilador();

  // Selecciona la velocidad del ventilador según el comando recibido
  switch (velocidad) {
    case 1:
      // Activa el pin correspondiente a la velocidad baja
      digitalWrite(velocidadBajaPin, HIGH);
      break;
    case 2:
      // Activa el pin correspondiente a la velocidad media
      digitalWrite(velocidadMediaPin, HIGH);
      break;
    case 3:
      // Activa el pin correspondiente a la velocidad alta
      digitalWrite(velocidadAltaPin, HIGH);
      break;
    default:
      break;
  }
}#include <SoftwareSerial.h>

// Define los pines de control para la velocidad del ventilador
const int velocidadBajaPin = 2;
const int velocidadMediaPin = 3;
const int velocidadAltaPin = 4;

// Inicializa el objeto de comunicación serial para Bluetooth
SoftwareSerial bluetoothSerial(10, 11); // RX, TX

void setup() {
  // Inicializa la comunicación serial para la depuración
  Serial.begin(9600);
  // Inicializa la comunicación serial para Bluetooth
  bluetoothSerial.begin(9600);

  // Configura los pines de control para la velocidad como salidas
  pinMode(velocidadBajaPin, OUTPUT);
  pinMode(velocidadMediaPin, OUTPUT);
  pinMode(velocidadAltaPin, OUTPUT);
}

void loop() {
  // Espera comandos desde el dispositivo emparejado a través de Bluetooth
  if (bluetoothSerial.available() > 0) {
     Serial.println("CONECTADO");
    // Lee el comando enviado desde el dispositivo Bluetooth
    String comando = bluetoothSerial.readString();
    // Imprime el comando recibido para depuración
    Serial.println("Comando recibido: " + comando);

    // Procesa los comandos recibidos
    if (comando == "encender") {
      encenderVentilador();
    } else if (comando == "apagar") {
      apagarVentilador();
    } else if (comando == "velocidad baja") {
      ajustarVelocidad(1);
    } else if (comando == "velocidad media") {
      ajustarVelocidad(2);
    } else if (comando == "velocidad alta") {
      ajustarVelocidad(3);
    }
  }
}

void encenderVentilador() {
  // Enciende el pin correspondiente a la velocidad baja del ventilador
  digitalWrite(velocidadBajaPin, HIGH);
}

void apagarVentilador() {
  // Apaga todos los pines de control del ventilador
  digitalWrite(velocidadBajaPin, LOW);
  digitalWrite(velocidadMediaPin, LOW);
  digitalWrite(velocidadAltaPin, LOW);
}

void ajustarVelocidad(int velocidad) {
  // Apaga todos los pines de control del ventilador
  apagarVentilador();

  // Selecciona la velocidad del ventilador según el comando recibido
  switch (velocidad) {
    case 1:
      // Activa el pin correspondiente a la velocidad baja
      digitalWrite(velocidadBajaPin, HIGH);
      break;
    case 2:
      // Activa el pin correspondiente a la velocidad media
      digitalWrite(velocidadMediaPin, HIGH);
      break;
    case 3:
      // Activa el pin correspondiente a la velocidad alta
      digitalWrite(velocidadAltaPin, HIGH);
      break;
    default:
      break;
  }
}
