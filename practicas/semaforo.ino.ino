// C++ code
//
/*
  este programa hace paradpadear el pin 13 del
  arduino
*/

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // enciende el pin 5
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  // esto es un comentario
  delay(1000); // Wait for 1000 millisecond(s)
  // apaga el pin 5
  digitalWrite(2, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  // apaga el pin 5
  digitalWrite(2, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}