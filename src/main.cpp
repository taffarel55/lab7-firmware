#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h"

WebServer server(80);

const char* ssid     = WIFI_NAME;
const char* password = WIFI_PASSWORD;

IPAddress ip(192,168,0,123); 
IPAddress gateway(192,168,0,1); 
IPAddress subnet(255,255,255,0);

uint8_t lightPin = 2;
bool lightStatus = LOW;

uint8_t outletPin = 0;
bool outletStatus = LOW;

uint8_t doorPin = 4;
bool doorStatus = LOW;

uint8_t airPin = 5;
bool airStatus = LOW;

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 Serial.print("Tamanho da página: ");
 Serial.print(s.length());
 Serial.println(" B");
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC() {
 // int a = 0;
 // a = analogRead(A0);      // ORIGINAL CODE
 // a = random(1,1023);      // RANDOM NUMBER
 // a = a + 1;                        // INCREASE
 // if (a >= 1024){a = 0;}
 // String adcValue = String(a);
 String adcValue = "20"; // SEND TEXT FROM SERIAL MONITOR.
 server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
}

void updateLight() {
  String ledStatusParam = server.arg("lightStatus");
  Serial.println(ledStatusParam);
  if (ledStatusParam == "ON")
    lightStatus =  HIGH;
  else
    lightStatus =  LOW;
  digitalWrite(lightPin, lightStatus);
  server.send(200, "text/plain", "Sucesso!");
}

void updateOutlet() {
  String outletStatusParam = server.arg("outletStatus");
  if (outletStatusParam == "ON")
    outletStatus =  HIGH;
  else
    outletStatus =  LOW;
  digitalWrite(outletPin, outletStatus);
 
  server.send(200, "text/plain", "Sucesso!");
}

void updateDoor() {
  String doorStatusParam = server.arg("doorStatus");
  if (doorStatusParam == "ON")
    doorStatus =  HIGH;
  else
    doorStatus =  LOW;
  digitalWrite(doorPin, doorStatus);
  server.send(200, "text/plain", "Sucesso!");
}


void updateAir() {
  String airStatusParam = server.arg("airStatus");
  String airTempParam   = server.arg("airTemp");
  if (airStatusParam == "ON")
    analogWrite(airPin,map(airTempParam.toInt(), 15, 28, 0, 1023));
  else
    digitalWrite(airPin, LOW);
  server.send(200, "text/plain", "Sucesso!");
}
 
 
void handleNotFound() {
  server.send(404, "text/plain", "Nao encontrado");
}

//===============================================================
// Setup
//===============================================================

void setup(void){

  pinMode(lightPin, OUTPUT);
  pinMode(outletPin, OUTPUT);
  pinMode(doorPin, OUTPUT);
  pinMode(airPin, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

/*
//ESP32 As access point
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);
*/
//ESP32 connects to your wifi -----------------------------------
  WiFi.mode(WIFI_STA); //Connectto your wifi
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readADC", handleADC);//To get update of ADC Value only
  server.on("/toggleLight", updateLight);
  server.on("/toggleOutlet", updateOutlet);
  server.on("/toggleDoor", updateDoor);
  server.on("/toggleAir", updateAir);
  server.onNotFound(handleNotFound);
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
}