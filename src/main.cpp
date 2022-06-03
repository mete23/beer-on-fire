#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "Car.h"
#include <SPIFFS.h>

const char *SSID = "beer-control";
const char *PASSWORD = "12345678";

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);
String webpage;

Car car(1,2,3,4);

void mainPage()
{
    server.send(200, "text/html", webpage);
}

void handlePost()
{
    int speed = server.arg("speed").toInt();
    int direction = server.arg("direction").toInt();
    car.move(speed, direction);
    Serial.print(direction);
    Serial.print(speed);
}

void setRoutes() {
    server.on("/", mainPage);
    server.on("/control", handlePost);
}

void setup()
{
    Serial.begin(9600);

    WiFi.softAP(SSID, PASSWORD);
    WiFi.softAPConfig(local_ip, gateway, subnet);

    SPIFFS.begin(true);
    webpage = SPIFFS.open("/main.html", "r").readString();
    Serial.println(webpage);

    setRoutes();
    server.begin();
    Serial.println("Server started!");
}

void loop()
{
    server.handleClient(); // server->send(200, "text/html", "htmltext here put");
}