#include "cyberpi.h"

CyberPi cyber;

int lo[7] = {48,50,52,53,55,57,59};
int mo[7] = {60,62,64,65,67,69,71};
int ho[7] = {72,74,76,77,79,81,83};
void data_recv(uint8_t* samples,int len) {
    cyber.clean_lcd();
    for(int i=0;i<len;i+=16)
    {
      int current = samples[i+1];
      cyber.set_lcd_pixel(i/16,current-64,0xffff);
    }
    cyber.render_lcd();
}
void setup() {
    Serial.begin(112500);
    delay(1000);
    cyber.begin();
    cyber.on_sound_data(data_recv);
    for(int i=0;i<14;i++)
    {
        cyber.set_instrument(i);
        int idx = 0;
        while(idx<7)
        {
            cyber.set_pitch(0,lo[idx],100);
            delay(600);
            idx++;
        }
        idx = 0;
        while(idx<7)
        {
            cyber.set_pitch(0,mo[idx],100);
            delay(600);
            idx++;
        }
        idx = 0;
        while(idx<7)
        {
            cyber.set_pitch(0,ho[idx],100);
            delay(600);
            idx++;
        }
    }
}

void loop() 
{
}