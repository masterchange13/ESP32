#include <Arduino.h>
#include <WiFi.h>


// put function declarations here:
int myFunction(int, int);

const char* ssid = "ChinaNet-h7tR";
const char* password = "88888888";

const char* ssid_create = "esp32";
const char* password_create = "12345678";

void setup() {
  // // put your setup code here, to run once:

  // connect to wifi and show ip address
  // int result = myFunction(2, 3);
  // Serial.begin(9600);

  // // 连接wifi
  // WiFi.begin(ssid, password);
  
  // // 检测是否连接成功
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial.println("Connecting to WiFi..");
  // }
  // Serial.println("Connected to the WiFi network");
  // Serial.println(WiFi.localIP());

  // create AP
  Serial.begin(9600);
  WiFi.softAP(ssid_create, password_create);
  // print ip
  Serial.println("ip address");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}