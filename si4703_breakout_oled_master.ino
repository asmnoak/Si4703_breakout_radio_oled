 /*
 * DSP Si4703 Radio control program on Arduino IDE
 *
 *  Created on: Jan. 14 , 2020
 *      Author: asmnoak
 *      support device is Arduino UNO (ATmega328P)
 *      support OLED(I2C)    2020/1/14
 *        I2C : A4(SDIO) and A5(SCLK)
 *        volume control : D4 and D5 (digitalread)
 *        station select : D3 (using interruption)
 *        volume value and selected station number are saved in EEPROM
 *        
 *        Customize updatestation() below to receive your area radio stations         
 *        and correct a line in station_setting() to check "max station number" 
 *        
*/

#include <Si4703_Breakout.h>  // by SparkFun  
#include "U8glib.h"   // search library manager to install
#include <Wire.h>
#include <EEPROM.h>
U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI OLED
int resetPin = 6;
int SDIO = A4;
int SCLK = A5;
Si4703_Breakout radio(resetPin, SDIO, SCLK);
int channel;
int volume;

int terminal_1  = 5;  // digital pin no. of volume control 
int terminal_2  = 4;  // same as abobe , volume up and down
//
int station = 0;          // broadcast station no.
unsigned long ct,pt,ct2,pt2;        //  interval time to avoid chattering
int event;                // event marker 
char szbuf1[16],szbuf2[16];  // diplay line1 and line2
//
void draw() {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);  // big font
  u8g.drawStr( 0, 16, szbuf1);
  u8g.drawStr( 0, 32, szbuf2);
}
void lcd_print() {
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  delay(50);
}

void setup()
{
  unsigned int upper,lower,raw_upper;
  unsigned int mask;
  delay(500);
  Serial.begin(9600);
  Wire.begin() ;
  //attachInterrupt(0,mode_setting, FALLING); // pin 2 (uno)
  attachInterrupt(1,station_setting, FALLING); // pin 3 (uno)
  sprintf(szbuf1,"%s","Hello!");
  sprintf(szbuf2,"%s","FM RADIO");
  lcd_print();
  pinMode(terminal_1, INPUT_PULLUP);
  pinMode(terminal_2, INPUT_PULLUP);
  //pinMode(2, INPUT_PULLUP);  // station_setting2
  pinMode(3, INPUT_PULLUP);  // station_setting
  digitalWrite(terminal_1, HIGH);
  digitalWrite(terminal_2, HIGH);
  //digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
//
  radio.powerOn();
  // set volume
  int val = EEPROM.read(1); // get volume value, address is 1
  Serial.println(val);
  if (val==0 || val >= 16) { //  val may be 255 at initial reset
     radio.setVolume(5);
     volume = 5;
  } else {
    if (val < 14) {  // set max val 13 at power on 
      radio.setVolume(val);
      volume = val;
    } else {
      radio.setVolume(9);
      volume = 9;
      EEPROM.write(1,9);  // save it
    }
  }
  //radio.setVolume(3);
  channel = 804; // ex. Air G FM frequency (value is MHz x 10)
  //volume = 3;
  station = 0;
  station = EEPROM.read(0); // get channel value, address is 0
  if (station >= 0 && station <= 15) { // channel val saved ?
    updatestation(station);    // set it
  } else {
    sprintf(szbuf1,"%s","Air G 80.4");
    radio.setChannel(channel);
  }
  //radio.setChannel(channel);
  displayInfo();
  delay(100);
  //sprintf(szbuf1,"%s","Air G 80.4");
  Serial.println(szbuf1);
  sprintf(szbuf2,"VOL: %d",volume);
  Serial.println(szbuf2);
  lcd_print();
  pt2=millis();
}///end of setup

void loop()
{
  int a = (PIND & _BV(4))>>4; // digitalread 4
  int b = (PIND & _BV(5))>>5; // digitalread 5
  if (a==0 || b==0) {
    updatevolume(a, b);
  }
//
  if (event==1) {
    Serial.print("event:");
    Serial.println(station);
    updatestation(station);    // set it
    displayInfo();
    delay(100);
    Serial.println(szbuf1);
    sprintf(szbuf2,"VOL:%d",volume);
    Serial.println(szbuf2);
    lcd_print();
    event=0;
  }  // event==1
}

void station_setting(){
  int sw;
  Serial.print("st:");
  Serial.println(station);
  ct2=millis();
  delay(10);  // no effect here
  sw=digitalRead(3);
  if ((ct2-pt2)>250) {
    station=station+1;
  }
  pt2=ct2;
  if(station>=6){  //// max station number 
    station=0;
  }
  event=1;
} 
void updatevolume(uint8_t a, uint8_t b)
{
  if (b==0) { // push vol up
    volume ++;
    if (volume>=16) volume=15;
  } else { // push vol down
    volume --;
    if (volume<=0) volume=0;
  }
  Serial.print("vl:");
  Serial.println(volume);
  EEPROM.write(1,volume);  // save it
  radio.setVolume(volume);
  sprintf(szbuf2,"VOL:%d",volume);
  displayInfo();
  lcd_print();
  delay(500);  // prevent chattering
}
void updatestation(int station){
    switch(station){
      case 0:
        channel=804; ////frequency MHz airg
        sprintf(szbuf1,"%s","Air G 80.4");
        break;
      case 1:
        channel=825; ////frequency MHz nw
        sprintf(szbuf1,"%s","NW 82.5");
        break;
      case 2:
        channel=852; ////frequency MHz NHK
        sprintf(szbuf1,"%s","NHK 85.2");
        break;
      case 3:
        channel=904; ////frequency MHz STV
        sprintf(szbuf1,"%s","STV 90.4");
        break;
      case 4:
        channel=915; ////frequency MHz HBC
        sprintf(szbuf1,"%s","HBC 91.5");
        break;
      case 5:
        channel=762; ////frequency MHz sankakuyama
        sprintf(szbuf1,"%s","Sankaku 76.2");
        break;
      default:
        channel=804; ////frequency MHz airg
        sprintf(szbuf1,"%s","Air G 80.4");
        break;
    }
    EEPROM.write(0,station);  // save it
    radio.setChannel(channel);  
}
void displayInfo()
{
   Serial.print("Channel:"); Serial.print(channel); 
   Serial.print(" Volume:"); Serial.println(volume); 
}    
