#include "measure.h"

TaskHandle_t handleTaskMeasurement, handleTaskSendData;

// WiFiClient client;
// HTTPClient http;

WiFiServer server(80);

IPAddress local_IP(192, 168, 1, 184);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

String MACAddress = WiFi.macAddress();

void taskMeasurement( void *pvParameters ) {
    for(;;) { 
        Serial.println("Realizando leituras");
        vTaskDelay(pdMS_TO_TICKS(10*DELAY_POOLING_MEASURE));
    }
}

void taskSendData( void *pvParameters ) {
    
}

void init_measure(void) {
    pinMode(SENSOR_CURRENT_PIN, INPUT); // TODO: Trocar para instância da lib

    server.begin();
    Serial.println("Servidor iniciado");

    Serial.print("IP para se conectar ao NodeMCU: "); //ESCREVE O TEXTO NA SERIAL
    Serial.print("http://"); //ESCREVE O TEXTO NA SERIAL
    Serial.println(WiFi.localIP()); //ESCREVE NA SERIAL O IP RECEBIDO DENTRO DA REDE SEM FIO (O IP NESSA PRÁTICA É RECEBIDO DE FORMA AUTOMÁTICA)

    xTaskCreatePinnedToCore(
        taskMeasurement,        /* Task function. */
        "taskMeasurement",      /* name of task. */
        10000,                  /* Stack size of task */
        NULL,                   /* parameter of the task */
        1,                      /* priority of the task */
        &handleTaskMeasurement, /* Task handle to keep track of created task */
        0                       /* pin task to core 0 */
    );             

      
    xTaskCreatePinnedToCore(
        taskSendData,           /* Task function. */
        "taskSendData",         /* name of task. */
        1000000,                /* Stack size of task */
        NULL,                   /* parameter of the task */
        1,                      /* priority of the task */
        &handleTaskSendData,    /* Task handle to keep track of created task */
        1                       /* pin task to core 1 */ 
    );               
}