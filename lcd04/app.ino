#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Analog.h>
#include <SimpleTimer.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
Analog temp(A0,40,-10);
SimpleTimer timer;

byte customChar[] = {0x1D,0x05,0x09,0x11,0x00,0x1F,0x11,0x1F};

byte high_temp[]={0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x1E};
byte middle_temp[]={0x00,0x00,0x00,0x0C,0x0C,0x0C,0x1E,0x1E};
byte low_temp[]={0x00,0x00,0x00,0x00,0x00,0x0C,0x1E,0x1E};

void check(){
    int value = temp.read();
    char buf[17];
    sprintf(buf,"Temp : %3d C", value);
    lcd.setCursor(0,0);
    lcd.print(buf);

    lcd.setCursor(0,1);
    if(value > 25){
        lcd.write(2);
    }else if(value>0){
        lcd.write(1);
    }else{
        lcd.write(0);
    }
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, low_temp);
  lcd.createChar(1, middle_temp);
  lcd.createChar(2, high_temp);
  timer.setInterval(100,check);
  }

void loop() {
    timer.run();
}