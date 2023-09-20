#include "wifi.h"

void init_wifi (void) {
  delay(1000);
  Serial.print("Connecting to wifi: ");
  Serial.println(WIFI_NAME);
  Serial.flush();

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}