#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string>
#include <ArduinoJson.h>

// put function declarations here:
int myFunction(int, int);

const char *ssid = "ChinaNet-h7tR";
const char *password = "88888888";

void setup()
{
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
    // login
    String request_url = "http://192.168.2.214:8080/page/test";
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
    String data = doc["data"].as<String>();
    Serial.printf("data: %s\n", data);
}

void loop()
{
    // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
    return x + y;
}
