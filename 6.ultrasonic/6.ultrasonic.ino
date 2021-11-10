//INISIALISASI
#include <OneWire.h>
#include <DallasTemperature.h>
#include <NewPing.h>
int r =5;
int y =6;
int g =7;
int buzzer =3;
int trig =11;
int echo =12;
int batas =400;


int sensorsuhu =8;

OneWire oneWire(sensorsuhu);
DallasTemperature sensors(&oneWire);
NewPing cm(trig,echo,batas);


void setup() {
Serial.begin(9600);
sensors.begin();
pinMode(buzzer, OUTPUT);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
  

}

void loop() {
//BACA SENSOR  
//sensors.requestTemperatures();
//float bacasuhu=sensors.getTempCByIndex(0);
int bacajarak=cm.ping_cm();
//SERIAL PRINT
Serial.print("data jarak : ");
Serial.print(bacajarak);
Serial.print(" cm");
Serial.println(); 
//SERIAL ULTRA
//LOGIKA
if(bacajarak <=20 and bacajarak > 0){
  digitalWrite(r, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
  Serial.println("berhenti");
  digitalWrite(buzzer, HIGH);
  delay(20);
  digitalWrite(buzzer, LOW);
  delay(30);
}else if(bacajarak >=21 and bacajarak <=70){
  Serial.println("warning");
  digitalWrite(r, LOW);
  digitalWrite(y, HIGH);
  digitalWrite(g,LOW);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(200);
}else if(bacajarak >=71 or bacajarak ==0){
  Serial.println("aman");
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, HIGH);
}
}
