#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingsBoard
const char* mqtt_server = "mqtt.thingsboard.cloud";
const char* token = "";

WiFiClient espClient;
PubSubClient client(espClient);

#define POT_PIN 34

float filteredRSSI = -70;
float alpha = 0.2;

bool humanDetected = false;
bool lastState = false;

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to ThingsBoard...");
    
    // Try to connect
    if (client.connect("ESP32_CLIENT", token, NULL)) {
      Serial.println("Connected!");
      break;
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, 1883);
  client.setKeepAlive(60);
  client.setSocketTimeout(30);
}

void loop() {

  if (!client.connected()) reconnect();
  client.loop();

  int realRSSI = WiFi.RSSI();

  filteredRSSI = alpha * realRSSI + (1 - alpha) * filteredRSSI;

  int potValue = analogRead(POT_PIN);
  float attenuation = map(potValue, 0, 4095, 0, 20);

  float effectiveRSSI = filteredRSSI - attenuation;

  humanDetected = attenuation > 8;

  if (humanDetected != lastState) {
    lastState = humanDetected;

    if (humanDetected) {
      Serial.println("STATE: MOTION DETECTED");
    } else {
      Serial.println("STATE: AREA CLEAR");
    }
  }

  String payload = "{";
  payload += "\"rssi\":" + String(effectiveRSSI) + ",";
  payload += "\"attenuation\":" + String(attenuation) + ",";
  payload += "\"state\":\"" + String(humanDetected ? "MOTION DETECTED" : "CLEAR") + "\"";
  payload += "}";

  bool published = client.publish("v1/devices/me/telemetry", payload.c_str());
  
  if (!published) {
    Serial.println("Publish failed!");
  }

  Serial.print("RSSI: ");
  Serial.print(effectiveRSSI);
  Serial.print(" | Attenuation: ");
  Serial.print(attenuation);
  Serial.print(" | State: ");
  Serial.println(humanDetected ? "MOTION DETECTED" : "CLEAR");

  delay(500);
}
