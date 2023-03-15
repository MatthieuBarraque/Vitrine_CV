#include "DHT.h"
#include <Servo.h>
#define DHTPIN0 A2     // what pin we're connected to
#define DHTPIN1 A0     // what pin we're connected to
#define GET2_TEMP() (analogRead(DHTPIN1))
#define DHTTYPE DHT11
#define SensorWPin A5 
#define WatterPin A4 
DHT dht0(DHTPIN0, DHTTYPE);
DHT dht1(DHTPIN1, DHTTYPE);
const int RELAY_PIN = A1;  
int servoPin = A3;
const int TEMP_THRESHOLD_UPPER = 18; 
const int TEMP_THRESHOLD_LOWER = 16; 
const int MinTemp=16;
const int MaxTemp=18;
int pos = 0;
float sensorValue = 0; 
Servo myservo; 

void setup() {
  Serial.begin(9600); 
  dht0.begin();
  dht1.begin();
  pinMode(RELAY_PIN, OUTPUT);
  myservo.attach(A3);
   pinMode(WatterPin, OUTPUT);
   delay(5000);
}
void AirAmbiant(){
 float t1 = dht1.readTemperature();
 
 if (isnan(t1)) {
    Serial.println("Failed to read from DHT sensor!");
  } else if(t1 > TEMP_THRESHOLD_UPPER){
      Serial.println("The fan is turned off");
      Serial.println(t1);
      digitalWrite(RELAY_PIN, LOW); // turn on
    } else if(t1 < TEMP_THRESHOLD_LOWER){
      Serial.println("The fan is turned on");
       Serial.println(t1);
      digitalWrite(RELAY_PIN, HIGH); // turn on
    }
}
void servom(){
  float t2 = dht0.readTemperature();
  
  if (t2 <= MinTemp) {
  for (pos = 90; pos <= 0; pos += 1) { 
  myservo.write(pos);
     delay(20);     
}
  }
  if (t2 >= MaxTemp) { 
  for (pos = 90; pos <= 0; pos += 1) { 
  myservo.write(pos);
   delay(20);     
}
  }
  else if (t2 = 28) {
  for (pos = 0; pos >= 90; pos -= 1){ 
  myservo.write(pos);
   delay(20);      
  }
  }
  Serial.println("DHT EXTERNE =");
 Serial.println(t2);
delay(1000);
 }
void waterinf() {
  sensorValue = analogRead(SensorWPin);
  sensorValue = ( 100 - ( (sensorValue/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(sensorValue);
  Serial.print("%\n\n");
  delay(1000);
}
void watering() {
  if (sensorValue < 65) {  
    digitalWrite(WatterPin, HIGH);
    delay(7000);
    digitalWrite(WatterPin, LOW);
    Serial.print("arrosage terminé");
  }
}
void loop() {
 AirAmbiant();
 servom();
 waterinf();
 watering();
  }