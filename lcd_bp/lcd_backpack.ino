#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
int push = 0;
int button;
int pastbutton;
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7);
void setup()
{
	lcd.begin(16, 2);
	lcd.setBacklightPin(3, POSITIVE);
	lcd.setBacklight(HIGH);
	lcd.print("yeet");
	pinMode(9, INPUT);
}

void loop()
{
	lcd.setCursor(0, 1);
	lcd.print(push);
	button = digitalRead(9);
	delay(1);
	pastbutton = digitalRead(9);
	if(button == HIGH && pastbutton == LOW){
		push += 1;

	}
	pastbutton = button;
	
}