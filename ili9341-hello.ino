#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PubSubClient.h>

#define TFT_DC 9
#define TFT_CS 10

// Configurações da rede Wi-Fi
const char* ssid = "wokwi-GUEST";
const char* password = "";

// Configurações do broker MQTT
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  tft.begin();
  tft.setRotation(3);  // Ajusta a rotação da tela, se necessário

  tft.setCursor(26, 120);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello, TFT!");

  tft.setCursor(20, 160);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("I can has colors?");

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  // Configura o servidor e as credenciais do MQTT
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCredentials(mqttUser, mqttPassword);

  // Conecta-se ao broker MQTT
  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP32Client")) {
      Serial.println("Conectado ao broker MQTT");
    } else {
      Serial.print("Falha na conexão com o broker MQTT - Tentando novamente em 5 segundos...");
      delay(5000);
    }
    mqttClient.subscribe("somar");
  }
}

void loop() {
  mqttClient.loop();  
 
}
