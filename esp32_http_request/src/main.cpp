#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string>
#include <ArduinoJson.h>

// put function declarations here:
int myFunction(int, int);

const char* ssid = "ChinaNet-h7tR";
const char* password = "88888888";

String url = "http://apis.juhe.cn/simpleWeather/query";
String key = "05cc6ee9f989505cc4acb5f97838d83a";
String city = "北京";

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  Serial.begin(9600);

  // 连接wifi
  WiFi.begin(ssid, password);
  
  // 检测是否连接成功
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  // 创建HttpClient对象
  HTTPClient http;
  
  // url
  String request_url = url + "?city=" + city + "&key=" + key;
  http.begin(request_url);

  // receive status
  int httpCode = http.GET();
  Serial.printf("状态码：%d\n", httpCode);

  // receive response
  String response = http.getString();

  Serial.println(response);

  // close http
  http.end();

  // create DynamicJsonDocument
  DynamicJsonDocument doc(1024);

  // load json 
  deserializeJson(doc, response);

  // get value from json
  // get temperature
  String area = doc["result"]["city"].as<String>();
  int temp = doc["result"]["realtime"]["temperature"].as<int>();
  String info = doc["result"]["realtime"]["info"].as<String>();
  int aqi = doc["result"]["realtime"]["aqi"].as<int>();

  Serial.printf("城市：%s, 温度：%d, 天气：%s, 空气指数：%d\n", area, temp, info, aqi);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}