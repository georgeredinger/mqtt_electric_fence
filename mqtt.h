#ifndef __mqtt__
#define __mqtt__ 1
#include <PubSubClient.h>
#include <WiFi.h>
extern PubSubClient client;
void setup_mqtt();
void setup_wifi();
void publish(const char *topic, const char *data);

#endif
