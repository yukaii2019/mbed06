#include "mbed.h"
#include "TextLCD.h"
Serial pc(USBTX,USBRX);
I2C i2c_lcd(D14,D15);

TextLCD_I2C lcd(&i2c_lcd, 0x4E,TextLCD::LCD16x2);

int main(){
    pc.printf("LCD Text. Columns=%d, Rows=%d\n\r",lcd.columns(),lcd.rows());
    for(int row=0;row<lcd.rows();row++){
        int col = 0;
        pc.printf("MemAddr(Col=%d, Row=%d)=0x%02X\n\r", col, row, lcd.getAddress(col, row));
        lcd.putc('0'+row);

        for(col = 1;col<lcd.columns()-1;col++){
        lcd.putc('*');
        }
        pc.printf("MemAddr(Col=%d, Row=%d)=0x%02X\n\r", col, row, lcd.getAddress(col, row));
        lcd.putc('+');
    }
    lcd.setCursor(TextLCD::CurOff_BlkOn);
    lcd.setUDC(0, (char *) udc_0);
    lcd.putc(0);
    lcd.setUDC(1, (char *) udc_1);
    lcd.putc(1);
}