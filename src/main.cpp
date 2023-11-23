#ifdef ESP32
  // ESP32 Libraries
  #include <WiFi.h>
  #include <WebServer.h>
#else
  // ESP8266 Libraries
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #include <WiFiClient.h>
#endif

#include <DNSServer.h>
#include <WiFiManager.h>
#include <DS3231.h>
#include <Wire.h>

#include "index.h"

WebServer server(80);

RTClib myRTC;
DS3231 Clock;

IPAddress ip(192,168,0,234); 
IPAddress gateway(192,168,0,1); 
IPAddress subnet(255,255,255,0);

uint8_t lightPin = 2;
bool lightStatus = LOW;

uint8_t outletPin = 4;
bool outletStatus = LOW;

uint8_t doorPin = 5;
bool doorStatus = LOW;

uint8_t splitPin = 18;
bool splitStatus = LOW;

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

void updateDevice() {
  String status = server.arg("status");
  String device = server.arg("device");

  Serial.print(device);
  Serial.print(" ");
  Serial.println(status);
  Serial.println(" ");

  int pin;

  if (device == "light")
    pin = lightPin;
  else if(device == "outlet")
    pin = outletPin;
  else if(device == "door")
    pin = doorPin;
  else if(device == "split")
    pin = splitPin;
  else
    Serial.println("Não existe esse device");

  digitalWrite(pin, status == "true" ? HIGH : LOW);
  	
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Sucesso!");
}
 
void handleNotFound() {
  server.send(404, "text/plain", "Nao encontrado");
}

void about() {
  server.send(200, "text/plain", "Trabalho de LAB 4 - Alípio, Handley, Maurício");
}

//===============================================================
// Setup
//===============================================================

int pin_reset = 15;

constexpr time_t tstmp {1700766944UL};
                        

void setup(void){

  pinMode(lightPin, OUTPUT);
  pinMode(outletPin, OUTPUT);
  pinMode(doorPin, OUTPUT);
  pinMode(splitPin, OUTPUT);

  pinMode (pin_reset, INPUT) ;

  Wire.begin();

  Serial.begin(115200);
  Serial.println();

  delay(10);

  Clock.setEpoch(tstmp, false);
  // set to 24h
  Clock.setClockMode(false);

  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout(60);

  //Create an AP (Access Point) with: ("network name", "network password")
  if (!wifiManager.autoConnect("LAB7")) {  
    Serial.println(F("Connection failed. Reset and try again..."));
    delay(3000);
    ESP.restart();
    delay(5000);
  }
  
  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
    Serial.print(".");
    delay(500);
  }

  // WiFi.config(ip, gateway, subnet);
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");

  Serial.print("IP address: http://");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  //----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readADC", handleADC);//To get update of ADC Value only
  server.on("/update", updateDevice);
  server.onNotFound(handleNotFound);
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();

  
      DateTime now = myRTC.now();
      
      Serial.print(now.year(), DEC);
      Serial.print('/');
      Serial.print(now.month(), DEC);
      Serial.print('/');
      Serial.print(now.day(), DEC);
      Serial.print(' ');
      Serial.print(now.hour(), DEC);
      Serial.print(':');
      Serial.print(now.minute(), DEC);
      Serial.print(':');
      Serial.print(now.second(), DEC);
      Serial.println();
  

  /*
  int value = digitalRead(pin_reset) ;
  if ( value == 1 ) {  
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    Serial.println("Settings reset!");
    ESP.restart();
  }
  */
}