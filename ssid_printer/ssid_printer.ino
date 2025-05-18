
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  // Modalità "Station" per poter scansionare
  WiFi.disconnect();    // Disconnessione da eventuale Wi-Fi
  delay(1000);

  Serial.println("Scansione delle reti Wi-Fi...");

  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("Nessuna rete trovata.");
  } else {
    Serial.println("Reti trovate:");
    for (int i = 0; i < n; ++i) {
      // Ottieni il MAC (BSSID) come puntatore a 6 byte
      uint8_t* mac = WiFi.BSSID(i);

      // Stampa SSID
      Serial.print("SSID: ");
      Serial.println(WiFi.SSID(i));

      // Stampa MAC address
      Serial.print("MAC: ");
      for (int j = 0; j < 6; j++) {
        if (mac[j] < 16) Serial.print("0"); // Aggiunge zero iniziale se necessario
        Serial.print(mac[j], HEX);
        if (j < 5) Serial.print(":");
      }
      Serial.println();

      // Stampa canale
      Serial.print("Canale: ");
      Serial.println(WiFi.channel(i));

      Serial.println("-----------------------");
    }
  }
}

void loop() {
}
