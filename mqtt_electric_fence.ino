#include <WiFi.h>
#include "creds.h"
#include "mqtt.h"

void setup() {
  const byte A0 = 32;
  const byte A1 = 33;
  const byte A2 = 34;
  const byte A3 = 35;

  Serial.begin(115200);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  setup_mqtt();
}

void loop() {
  int maxv[4];
  char ssum[10];
  maxv[0] = 0;
  maxv[1] = 0;
  maxv[2] = 0;
  maxv[3] = 0;
  analogReadResolution(9);//9..12
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 4; j++) {
      int v = analogRead(j + 32);
      if (v > maxv[j]) maxv[j] = v;
    }
    delay(2);
  }
  //Serial.printf("%d %d %d %d\n",  maxv[0], maxv[1], maxv[2], maxv[3]);
  int sum = maxv[0] + maxv[1] * 2 + maxv[3] * 4 + maxv[3] * 8;
  sprintf(ssum, "%d", sum);
  Serial.printf("%s\n", ssum);
  publish("fence/data", ssum);
  delay(60000);
}
