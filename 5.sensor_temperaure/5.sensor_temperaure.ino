//INISIALISASI
#include <OneWire.h>
#include <DallasTemperature.h>
int r =5;
int y =6;
int g =7;
int buzzer =3;

int sensorsuhu =8;
OneWire oneWire(sensorsuhu);
DallasTemperature sensors(&oneWire);


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
sensors.requestTemperatures();
float bacasuhu=sensors.getTempCByIndex(0);
//SERIAL PRINT
Serial.print("suhu : ");
Serial.print(bacasuhu);
Serial.print(" 0 ");
Serial.println(); 

//LOGIKA
if(bacasuhu >=31){
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  Serial.println("NORMAL");
  digitalWrite(buzzer, HIGH);
  delay(20);
   digitalWrite(g, LOW);
  digitalWrite(buzzer, LOW);
  delay(30);
}else{
  digitalWrite(r, LOW);
  digitalWrite(g,HIGH);
  digitalWrite(buzzer, LOW);
  Serial.println("DANGER");
  delay(100);
 
}
}
