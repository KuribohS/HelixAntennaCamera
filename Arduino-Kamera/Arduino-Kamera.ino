
//Voltage messuar stuff
const float referenceVolts = 5.0;
const int batteryPin = 0;

int LED1 = 8;
 
void setup(){
    // Setup Serial Monitor
    Serial.begin(9600);
    //Serial.println("DC Voltage Test");
    pinMode(LED1, OUTPUT);
    digitalWrite(LED1, HIGH);
    
}
 
void loop(){
    int val = analogRead(batteryPin);
    float volts = (val / 1023.0) * referenceVolts;
    Serial.println(volts);
    delay(200);

}