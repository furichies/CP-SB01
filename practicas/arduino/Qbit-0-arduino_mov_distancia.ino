// MOVIMIENTO DEL ROBOT POR CONTROL DFE DISTANCIA. CODE REACONDICIONADO XD
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

// Motor A
int ENA = 6;
int IN1 = 13;
int IN2 = 12;

// Motor B
int ENB = 5;
int IN3 = 11;
int IN4 = 10;

int vel = 200;

// Ultra Sonido
const float sonido = 34300.0; // Velocidad del sonido en cm/s

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void Atras()
{
  //Direccion motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, vel); //Velocidad motor B
}

void Adelante()
{
  //Direccion motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, vel);  //Velocidad motor A
  //Direccion motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, vel); //Velocidad motor B
}

void Izquierda()
{
  //Direccion motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, vel); //Velocidad motor A
}

void Derecha()
{
  //Direccion motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, vel); //Velocidad motor A
}

void Parar()
{
  //Direccion motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); //Velocidad motor A
  //Direccion motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); //Velocidad motor A
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  // Declaramos todos los pines como salidas
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  long distancia = readUltrasonicDistance(3, 2);

  // Motor gira en un sentido
  if (distancia > 30) {
    Adelante();
  } else if (distancia > 15) {
    Izquierda();
  } else if (distancia > 5) {
    Derecha();
  } else {
    Atras();
  }

  // Si la distancia es mayor que 14cm, enciende el LED
  if (distancia > 14) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100); // Espera para no sobrecargar el procesador
}

