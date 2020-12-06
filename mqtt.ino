#include "mqtt.h"
#include "creds.h"

IPAddress broker(192, 168, 1, 113); // IP address of your MQTT broker eg. 192.168.1.50
WiFiClient wclient;
PubSubClient client(wclient); // Setup MQTT client

#define ID "theFence"

// Connect to WiFi network
void setup_wifi() {
  WiFi.begin(SSID, PASSWORD); // Connect to network
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(1500);
  }
  Serial.println("connected");
  Serial.println(SSID);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(ID)) {
      Serial.printf(" MQTT connected as %s\n", ID);
    } else {
      Serial.print("MQTT connect failed with state ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void publish(const char *topic, const char *data) {
  if (!client.connected()) { // Reconnect if connection is lost
    reconnect();
  }
  client.loop();
  client.publish(topic, data);
  Serial.printf("%s %s\n", topic , data);

}

void setup_mqtt() {
  setup_wifi(); // Connect to network
  client.setServer(broker, 1883);

}
