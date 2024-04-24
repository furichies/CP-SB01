#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "latrampa";
const char* password = "987654321";

ESP8266WebServer server(80);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  delay(10);

  // Conectar a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado a la red WiFi");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Rutas para la interfaz web
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
}

// Manejador para la página principal
void handleRoot() {
  server.send(200, "text/html", "<html><head><title>Control LED</title></head><body><h1>Control LED</h1><form action=\"/on\" method=\"get\"><button>Encender LED</button></form><br><form action=\"/off\" method=\"get\"><button>Apagar LED</button></form></body></html>");
}

// Manejador para encender el LED
void handleOn() {
  digitalWrite(LED_BUILTIN, HIGH);
  server.send(200, "text/html", "<html><head><title>LED Encendido</title></head><body><h1>LED Encendido</h1><a href=\"/\">Volver</a></body></html>");
}

// Manejador para apagar el LED
void handleOff() {
  digitalWrite(LED_BUILTIN, LOW);
  server.send(200, "text/html", "<html><head><title>LED Apagado</title></head><body><h1>LED Apagado</h1><a href=\"/\">Volver</a></body></html>");
}

