#line 1 "c:\\IOT\\arduino2\\minicom\\MiniCom.h"
#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

class MiniCom{
    protected:
        long serial_bps;
        LiquidCrystal_I2C lcd;
        SimpleTimer timer;
        bool no_lcd;
    
    public:
        Minicom(long serial_bps=115200,int lcd_addr=0x27);
        void setNolcd(){no_lcd = true;};
        void init();
        void run();

        int setInterval(unsigned long interval, timer_callback f);
        SimpleTimer& getTimer(){return timer;}

        void print(int row, const char *pMsg);
        void print(int row, String title, int value);
        void print(int row, String title1, int value1, Stinrg title2,  int value2);
        void print(int row, String title, double value);
        void print(int row, String title1, double value1, String title2, double value2);
}