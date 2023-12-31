#include <LiquidCrystal.h>
#include<Servo.h>

    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    Servo servo;
    int trig=10;
    int echo=9;
    void setup() {
        lcd.begin(16, 2);
        Serial.begin(9600);
        servo.attach(7);
        servo.write(0);
        pinMode(trig,OUTPUT);
        pinMode(echo,INPUT);
        lcd.setCursor(4, 0);
        lcd.print("WELCOME");
        delay(2000);
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Project By:");
        lcd.setCursor(3,1);
        lcd.print("Project by Sage Students");
        delay(4000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Smart Dustbin");
        delay(2000);
    }
    void loop(){
        digitalWrite(trig,LOW);
        delayMicroseconds(5);
        digitalWrite(trig,HIGH);
        delayMicroseconds(10);
        digitalWrite(trig,LOW);
        int a =pulseIn(echo,HIGH);
        int distance = a*0.0343/2;
        Serial.println(distance);

        if(distance<50){
            servo.write(90);
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("Dustbin opened");
            delay(500);
        }
        else{
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("Dustbin closed");
            delay(500);
            servo.write(0);
        }
    }
