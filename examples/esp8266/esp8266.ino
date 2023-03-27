#include <TM1637.h>
#include <Ticker.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
const char *ssid     = "???";
const char *password = "???";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"ntp.ix.ru", 10800);
int8_t TimeDisp[] = {0x00,0x00,0x00,0x00,0x00,0x00};
#define CLK 12 //D6  GPIO12
#define DIO 13 //D7  GPIO13
TM1637 tm1637(CLK,DIO);
Ticker points;
boolean point;
unsigned long timing;

void setup() {
tm1637.set(BRIGHT_TYPICAL);          
tm1637.init();          

WiFi.begin(ssid, password);
while ( WiFi.status() != WL_CONNECTED ) {
delay ( 500 );
}
timeClient.begin();
}

void loop() {
timeClient.update();

if (millis() - timing > 1000){ 
timing = millis(); 
points.attach(1, blink_points);
}
  
tm1637.point(point);
TimeDisp[0] = timeClient.getHours() / 10;                                          
TimeDisp[1] = timeClient.getHours() % 10;            
TimeDisp[2] = timeClient.getMinutes() / 10;         
TimeDisp[3] = timeClient.getMinutes() % 10;   
TimeDisp[4] = timeClient.getSeconds() / 10;         
TimeDisp[5] = timeClient.getSeconds() % 10;      
tm1637.display(TimeDisp);         
}

void blink_points(){ 
point = !point;
} 
