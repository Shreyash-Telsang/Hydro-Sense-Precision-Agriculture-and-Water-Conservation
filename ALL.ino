#include <DHT.h>;
#include <OneWire.h>
#include <DallasTemperature.h>


#define DHTPIN 2
#define trigPin 3
#define echoPin 4
#define moist1 A0
#define moist2 A1
#define moist3 A2
#define DHTTYPE DHT22
#define ONE_WIRE_BUS_1 5   
#define ONE_WIRE_BUS_2 6   
#define ONE_WIRE_BUS_3 7   
DHT dht(DHTPIN, DHTTYPE);

OneWire oneWire1(ONE_WIRE_BUS_1);
OneWire oneWire2(ONE_WIRE_BUS_2);
OneWire oneWire3(ONE_WIRE_BUS_3);


DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);



const int OpenAirReading = 700;   
const int WaterReading = 280;    

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(moist1,INPUT);
  pinMode(moist2,INPUT);
  pinMode(moist3,INPUT);
  dht.begin();
  sensors1.begin();
  sensors2.begin();
  sensors3.begin();

}

void loop() {
  // put your main code here, to run repeatedly:



}


int dhtHum(){
  int hum = dht.readHumidity();
  return hum;
}

int distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration*.0343)/2;
  return distance;
}

int moisture1(){
  int MoistureLevel = analogRead(moist1);
  int SoilMoisturePercentage = map(MoistureLevel, OpenAirReading, WaterReading, 0, 100);
  return SoilMoisturePercentage;
}

int moisture2(){
  int MoistureLevel = analogRead(moist2);
  int SoilMoisturePercentage = map(MoistureLevel, OpenAirReading, WaterReading, 0, 100);
  return SoilMoisturePercentage;
}


int moisture3(){
  int MoistureLevel = analogRead(moist3);
  int SoilMoisturePercentage = map(MoistureLevel, OpenAirReading, WaterReading, 0, 100);
  return SoilMoisturePercentage;
}

int getTemp1(){
    sensors1.requestTemperatures(); 
    return (sensors1.getTempCByIndex(0)); 

}

int getTemp2(){
    sensors2.requestTemperatures(); 
    return (sensors3.getTempCByIndex(0)); 

}

int getTemp3(){
    sensors2.requestTemperatures(); 
    return (sensors3.getTempCByIndex(0)); 

}

