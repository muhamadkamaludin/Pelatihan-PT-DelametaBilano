//INISIALISASI 
int sensorFLAME =A1;
int buzzer    =5;
int r         =9;
int y         =10;
int g         =11;         

void setup() {
  Serial.begin(9600);
  pinMode(sensorFLAME, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  
}

void loop() {
  //BACA DATA
  int bacaFLAME=analogRead(sensorFLAME);
      bacaFLAME=map(bacaFLAME,1016,22,0,100);
                  //(data awal sensor,data akhir sensor,nilai yang diinginkan,nilai akhir yang diinginkan)
  
  //PRINT SERIAL
  Serial.print("Nilai FLAME : ");
  Serial.println(bacaFLAME);
  //Serial.print();

  //LOGIKA
  if(bacaFLAME ==0){
    delay (100);
    Serial.println("aman");
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);  
  }
  else if (bacaFLAME >=20 and bacaFLAME <=50){
    Serial.println("Warning");
    digitalWrite(r, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
  else if (bacaFLAME > 50){
    Serial.println("Lari Mengungsi");
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  
  



}
