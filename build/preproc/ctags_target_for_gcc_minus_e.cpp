# 1 "c:\\IOT\\arduino2\\minicom\\MiniCom.cpp"
# 2 "c:\\IOT\\arduino2\\minicom\\MiniCom.cpp" 2

MiniCom::MiniCom(long serial_bps, int lcd_addr)
    :serial_bps(serial_bps), lcd(lcd_addr, 16,2){
        no_lcd = false;
}

void MiniCom::init(){
    Serial.begin(serial_bps);
    if(!no_lcd){
        lcd.init();
        lcd.backlight();
    }
}

int MiniCom::setInterval(unsigned long interval, timer_callback f){
    return timer.setInterval(interval, f);
}

void MiniCom::run(){
    timer.run();
}

void MiniCom::print(int row, const char *pMsg)
{
    if(no_lcd) return;
    char buf[17];
    sprintf(buf, "%-16s", pMsg);
    lcd.setCursor(0,row);
    lcd.print(buf);
}

void MiniCom::print(int row, String title1, int value1,
String title2, int value2)
{
    if(no_lcd) return;
    String buf = title1 + value1 + "," + title2 + value2;
    print(row, buf.c_str());
}

void MiniCom::print(int row, String title, double value)
{
    if(no_lcd) return;
    String buf = title + value;
    print(row, buf.c_str());
}

void MiniCom::print(int row, String title1, double value1,
String title2, double value2)
{
    if(no_lcd) return;
    String buf = title1 + value1 + "," + title2 + value2;
    print(row, buf.c_str());
}
# 1 "c:\\IOT\\arduino2\\minicom\\app.ino"

# 3 "c:\\IOT\\arduino2\\minicom\\app.ino" 2



void setup(){

}
void loop(){

}
