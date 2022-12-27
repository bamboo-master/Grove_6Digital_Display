#include "TM1637.h"

int8_t TimeDisp[] = {0x00,0x00,0x00,0x00,0x00,0x00};


#define CLK 12 //D6  GPIO12
#define DIO 13 //D7  GPIO13

TM1637 tm1637(CLK,DIO);

void setup() {
  
  tm1637.set(BRIGHTEST);          
  tm1637.init();          

}

void loop() {

int h=12;
int m=34;
int s=56;

 tm1637.point(POINT_ON);
 TimeDisp[0] = h / 10;                                          
 TimeDisp[1] = h % 10;            
 TimeDisp[2] = m / 10;         
 TimeDisp[3] = m % 10;   
 TimeDisp[4] = s / 10;         
 TimeDisp[5] = s % 10;      
 tm1637.display(TimeDisp);         
                        
                             
}
