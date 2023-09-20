#ifndef LIB_MEASURE_H
#define LIB_MEASURE_H

#include <Arduino.h>
// #include "EmonLib.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "wifi.h"

#define DELAY_POOLING_MEASURE 500
#define DELAY_POOLING_SEND_MEASURE 10000
#define SENSOR_CURRENT_PIN A0

#define UUID String(ESP.getEfuseMac())

void init_measure(void);

#endif // LIB_MEASURE_H