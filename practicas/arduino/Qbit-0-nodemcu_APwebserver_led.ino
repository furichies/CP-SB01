#include <ESP8266WiFi.h>

// Definir el nombre de tu red WiFi y la contraseña (en este caso, no tiene contraseña)
const char* ssid = "RedNodemcu";
const char* password = "";

// Crear un servidor web en el puerto 80
WiFiServer server(80);

void setup() {
  // Iniciar el puerto serie para el monitor serial
  Serial.begin(115200);
  
  // Conectar a la red WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  
  // Iniciar el servidor web
  server.begin();
  
  Serial.println("Servidor iniciado");
}

void loop() {
  // Esperar a que se conecte un cliente
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Esperar hasta que el cliente envíe algunos datos
  while(!client.available()){
    delay(1);
  }
  
  // Leer la solicitud HTTP del cliente
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  // Comprobar si la solicitud contiene "LED=ON"
  if (request.indexOf("LED=ON") != -1) {
    digitalWrite(LED_BUILTIN, HIGH); // Encender el LED
  } else if (request.indexOf("LED=OFF") != -1) {
    digitalWrite(LED_BUILTIN, LOW); // Apagar el LED
  }
  
  // Enviar la respuesta HTTP al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  
  // Página web para controlar el LED
  client.println("<!DOCTYPE html><html>");
  client.println("<head><title>Control de LED</title></head>");
  client.println("<body>");
  client.println("<h1>Control de LED</h1>");
  client.println("<p><a href=\"LED=ON\">Encender LED</a></p>");
  client.println("<p><a href=\"LED=OFF\">Apagar LED</a></p>");
  client.println("</body></html>");
  
  delay(10);
  
  // Cerrar la conexión
  client.stop();
}

