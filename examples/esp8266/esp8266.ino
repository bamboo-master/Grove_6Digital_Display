#include "TM1637.h"
#include "Ticker.h"


int8_t TimeDisp[] = {0x00,0x00,0x00,0x00,0x00,0x00};


#define CLK 12 //D6  GPIO12
#define DIO 13 //D7  GPIO13

TM1637 tm1637(CLK,DIO);

Ticker points;
boolean point;

unsigned long h, m, s, timing;

void setup() {
  
  tm1637.set(BRIGHTEST);          
  tm1637.init();          

}

void loop() {

h=12;
m=34;
s=56;

 if (millis() - timing > 1000){ 
 timing = millis(); 
 points.attach(1, blink_points);
 }
  
 tm1637.point(point);
 TimeDisp[0] = h / 10;                                          
 TimeDisp[1] = h % 10;            
 TimeDisp[2] = m / 10;         
 TimeDisp[3] = m % 10;   
 TimeDisp[4] = s / 10;         
 TimeDisp[5] = s % 10;      
 tm1637.display(TimeDisp);         
                            
}

void blink_points(){ 
  point = !point;
 } 

