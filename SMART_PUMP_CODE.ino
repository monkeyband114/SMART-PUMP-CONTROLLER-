/*
 *This project was created by Michael adawaren and will be updated by Michael Adawaren copyright will include using the code for personal 
   purpose only and not publishing it for more inquires contact me at gadocer54@gmail.com
 */
#include <stdlib.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define echoPin 2 
#define trigPin 3 

#define relay A0
#define interval 1000

long durag; 
int dist; 
int dist2;
int fry = 100;
int diy = 95;
int ply = 7;
int fullTank;
int addr = 0;
int addr1 = 1;
int emtyTank;
int emtyTank2;
int fullTank2;
int valu;
int TankHeight;
int  value1;



void pumpNotworking(){
     for (int k =2; k <=50000;k++){

      Serial.println(" PUMP NOT WORKING  ");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PUMP NOT WORKING ");
        digitalWrite(relay, HIGH);
        delay(68000);
        lcd.clear();
   
     }
  
}
void setup() {
   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  delay(2000);
  digitalWrite(relay, LOW);
  delay(3000);
  digitalWrite(relay, HIGH);
 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("welcome smart punp "); 
  Serial.println("nice eh now ");

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durag = pulseIn(echoPin, HIGH);
  
  dist = durag * 0.034 / 2;
 
     
  Serial.print("tankheight: ");
  lcd.setCursor(0,1);
       lcd.print("TANK HEIGHT:");
  Serial.print(dist);
   lcd.print(dist);
    lcd.println("cm");
  Serial.println(" cm");
  EEPROM.write(addr, dist);
  TankHeight =  EEPROM.read(addr);
  delay(4000);
  lcd.clear();
  }
  
 void calculate(){ 
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durag = pulseIn(echoPin, HIGH);
  dist2 = durag * 0.034 / 2;
Serial.print("tank level now at: "); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TANK LVL AT :");
  lcd.print(dist2); 
  lcd.print("cm");
  lcd.setCursor(1,0);
  lcd.print("PUMP WORKING");
Serial.print(dist2);
Serial.println(" cm");
}
  
void loop() {
    // put your main code here, to run repeatedly:
   emtyTank = TankHeight * 50/100;
   emtyTank = TankHeight - emtyTank;
   emtyTank2 = emtyTank - 3;
   fullTank = TankHeight * 91/100;
   fullTank = TankHeight - fullTank;
   fullTank2 = fullTank - 3;

calculate();


if (dist2 <= fullTank){
       Serial.println("tank is full");
       lcd.clear();
       lcd.setCursor(0,1);
       lcd.println("tank is full");
       lcd.setCursor(1,0);
       lcd.println("PUMP TURNED OFF");
  //  write you relay pump code here 

   digitalWrite(relay, HIGH);
   delay(interval);
  }
  
  else if (dist2 > emtyTank  ){
       Serial.println("tank is emty");
       lcd.clear();
       lcd.setCursor(0,1);
       lcd.print("TANK IS EMTY");
       lcd.setCursor(1,0);
       lcd.print("PUMP TURNED ON");
      // write your relay pump code here 
       digitalWrite(relay, LOW);
        EEPROM.write(addr1,dist2);
       value1 = EEPROM.read(addr1);
       Serial.print("eeprom value:");
       Serial.println(value1);
       delay(30000);
       calculate();
      
       if (value1 <= dist2){
    
        Serial.println(" PUMP NOT WORKING  ");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PUMP NOT WORKING ");
        digitalWrite(relay, HIGH);
        delay(8000);
        lcd.clear();
        for (int k =2; k <=50000;k++){

      Serial.println(" THIS IS FUSTRATING   ");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("CHEAK PUMP");
        digitalWrite(relay, HIGH);
        delay(68000);
        lcd.clear();
   
     }
    }
    }
  



  else{
      
        Serial.println(" distyujojlkl ");
         delay(1000);
        Serial.println(emtyTank); 
        Serial.println(fullTank);
      }
    
}
