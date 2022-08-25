#include <LiquidCrystal_I2C.h>
#include <Button.h>
#include <SimpleTimer.h>
#include <Analog.h>

LiquidCrystal_I2C lcd(0x27,16,2);
SimpleTimer timer;
Analog sensor(A0,1023,0);

void check(){
    int value = sensor.read();
    char buf[5];
    sprintf(buf, "%4d", value);

    lcd.setCursor(0,0);
    lcd.print(buf);
}

void setup(){
    lcd.init();
    lcd.backlight();
    timer.setInterval(100,check);
}
void loop(){
    timer.run();
}