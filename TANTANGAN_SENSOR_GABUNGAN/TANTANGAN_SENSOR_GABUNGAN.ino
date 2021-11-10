//INISIALISASI 
int sensorFLAME =A1;
int sensorLDR   =A0;
int sensorPIR   =2;
int buzzer      =5;
int r           =9;
int y           =10;
int g           =11;         

void setup() {
  Serial.begin(9600);
  pinMode(sensorFLAME, INPUT);
  pinMode(sensorPIR, INPUT);
  pinMode(sensorLDR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  
}

void loop() {
  //BACA DATA FLAME
  int bacaFLAME=analogRead(sensorFLAME);
      bacaFLAME=map(bacaFLAME,1016,22,0,100);
  //BACA DATA LDR
  int bacaLDR=analogRead(sensorLDR);
      bacaLDR=map(bacaLDR,0,1024,0,255);
  //BACA DATA PIR
  int bacaPIR=digitalRead(sensorPIR);  
      
                  
  
  //PRINT SERIAL FLAME
  Serial.print("Nilai FLAME : ");
  Serial.println(bacaFLAME);
  //Serial.print();

  //PRINT SERIAL LDR
  Serial.print("Nilai LDR : ");
  Serial.println(bacaLDR);

  //PRINT SERIAL PIR
  Serial.print("Nilai PIR : ");
  Serial.println(bacaPIR);

  //LOGIKA
  if(bacaFLAME ==0){
    delay (100);
    digitalWrite(buzzer, LOW);
    
  }
  else if (bacaFLAME >=20 and bacaFLAME <=50){
    Serial.println("Warning");
    analogWrite(buzzer, 100);
    delay(500);
  }
  else if (bacaFLAME > 50){
    Serial.println("Lari Mengungsi");
    analogWrite(buzzer,255);
    delay(500);
  }
  
  //LOGIKA
  analogWrite(r,bacaLDR);
  analogWrite(y,bacaLDR);
  analogWrite(g,bacaLDR);

  
  
  



}
