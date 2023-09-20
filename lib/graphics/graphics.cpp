#include "graphics.h"

void print_banner(void) {

    Serial.begin(115200);
    delay(1000);

    Serial.println("   ______________________________");
    Serial.println(" / \\                             \\.");
    Serial.println("|   |     Firmware Solutions     |.");
    Serial.println(" \\_ |                            |.");
    Serial.println("    |   Leia o README antes de   |.");
    Serial.println("    |   carregar o código no     |.");
    Serial.println("    |   microcontrolador.        |.");
    Serial.println("    |                            |.");
    Serial.println("    |             by: taffarel55 |.");
    Serial.println("    |      contact@taffarel.tech |.");
    Serial.println("    |   _________________________|___");
    Serial.println("    |  /                            /.");
    Serial.println("    \\_/____________________________/.");
    Serial.println("");
    Serial.print("ID da Placa: "); 
    Serial.print(UUID); 
    Serial.println("\n");
}