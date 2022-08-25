#include <LiquidCrystal_I2C.h>
#include <Button.h>
#include <SimpleTimer.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Button btn(3);
SimpleTimer timer;

// boolean bBacklight = false;

void backlightoff(){
    lcd.noBacklight();
}

void backlightOnOff(){ // 버튼 처리 핸들러
    lcd.backlight();
    timer.setTimeout(3000,backlightoff);

    // bBacklight = !bBacklight;
    // if(bBacklight){
    //     lcd.backlight();
    // }else{
    //     lcd.noBacklight();
    // }
}

void setup(){
    btn.setCallback(backlightOnOff);
    lcd.init();

    lcd.setCursor(0,0);
    lcd.print("one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve");

    lcd.setCursor(0,1);
    lcd.print("one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve");
}

void loop(){
    int n;

    btn.check();

    timer.run();

    // for(n=0;n<80;n++){
    //     lcd.scrollDisplayLeft();
    //     delay(500);
    // }
    // delay(4000);

    // for(n=0;n<80;n++){
    //     lcd.scrollDisplayRight();
    //     delay(500);
    // }
    // delay(4000);
}