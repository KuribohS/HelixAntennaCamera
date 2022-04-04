#include <Servo.h>


//Switch Input
int Switch = A0;
int Switchsatus = 0;
//servo configure
Servo Servo1;
Servo Servo2;

//aditional power
#define ANALOG_IN_PIN A0
#define VCC2 5
#define GND2 2

//Lights
int LED1 = 7;
int LED2 = 3;



void setup(){

    Servo1.write(90);
    Servo2.write(90);
    

    //servo
    Servo1.attach(9);
    Servo2.attach(10);
    
    // Setup Serial Monitor
    Serial.begin(9600);



    //LED'S
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);


    //Add aditional 5V and Gound Pins
    pinMode(VCC2, OUTPUT);
    digitalWrite(VCC2, HIGH);

    pinMode(GND2,OUTPUT);
    digitalWrite(GND2,LOW);
    
    
}

void loop(){ 
    Switchsatus = digitalRead(Switch);
    Serial.println(Switchsatus);
    if (Switchsatus == HIGH){
        Servo1.write(90);
        delay(200);
        Servo2.write(90);
        digitalWrite(LED2, HIGH);
    }
    else{
        Servo1.write(0);
        delay(200);
        Servo2.write(0);
        digitalWrite(LED2, LOW);
    }
}