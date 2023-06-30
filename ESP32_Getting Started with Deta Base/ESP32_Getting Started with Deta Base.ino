#include <detaBaseArduinoESP32.h>
#include <WiFiClientSecure.h>
#define LED 2

char* apiKey = "U942eCgM_2RrBrvCWPZhHgTAMuHtrxyLifdchiEUG";
char* detaID = "U942eCgM";
char* detaBaseName = "Test";

WiFiClientSecure client;
DetaBaseObject detaObj(client, detaID, detaBaseName, apiKey, true);


void setup() {
  Serial.begin(115200);
  Serial.println("Let's begin initialization");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println("Reached before WiFi init");
  WiFi.begin("SINGTEL-DPH4", "Home147532"); //replace WIFI_SSID, WIFI_PASSWORD
  Serial.println("Waiting to connect to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  digitalWrite(LED, HIGH);

}

// PUT "{\"items\":[{\"age\":4}]}"

//INSERT "{\"item\":{\"key\":\"cba\",\"age\":4}}"

//INSERT "{\"item\":{\"key\":\"abc\",\"age\":4}}"

//UPDATE "{\"increment\":{\"age\":1}}", key:abc

//UPDATE "{\"increment\":{\"age\":1}}", key:cba

//QUERY "{\"query\":[{\"age?lt\": 10}]}"

void loop() {
  printResult(detaObj.putObject("{\"items\":[{\"age\":4}]}"));
  Serial.println();
  printResult(detaObj.getObject("cba"));
  Serial.println();
  printResult(detaObj.deleteObject("abc"));
  Serial.println();
  printResult(detaObj.insertObject("{\"item\":{\"key\":\"cba\",\"age\":4}}"));
  Serial.println();
  printResult(detaObj.insertObject("{\"item\":{\"key\":\"abc\",\"age\":4}}"));
  Serial.println();
  printResult(detaObj.updateObject("{\"increment\":{\"age\":1}}", "abc"));
  Serial.println();
  printResult(detaObj.updateObject("{\"increment\":{\"age\":1}}", "bcs"));
  Serial.println();
  printResult(detaObj.query("{\"query\":[{\"age?lt\": 10}]}"));
  Serial.println();

  while (true);
}
