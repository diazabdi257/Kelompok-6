#include <LiquidCrystal.h>					
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int led1 = 8;
int led2 = 9;
int buzzpin = 10;
int button = 11;

void setup () {
  Serial.begin(9600);
  
  pinMode(button, INPUT);
  
  pinMode(led1 ,OUTPUT);
  pinMode(led2 ,OUTPUT);
  
  pinMode(buzzpin, OUTPUT);
  
  lcd.begin(16, 2);

}

void loop ()
  {  
  if(digitalRead(button) == 1) { 
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    
    tone(buzzpin, 262, 20000); // tone(buzzpin, frekuensi, durasi); ini untuk piezo/buzzer
      
    lcd.display(); // menyalakan LCD
    lcd.setCursor(0,0); //lcd.setCursor(column, row)
    lcd.print("Hati-hati! ada");
    lcd.setCursor(0,1); // LCD baris kedua
    lcd.print("penyebrang jalan");
    
    delay(20000);
    
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    
      lcd.noDisplay(); //mematikan LCD
    	
    }
	delay(100);
  
}