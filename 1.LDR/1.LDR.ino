//INISIALISASI 
int sensorLDR =A1;
int buzzer    =5;
int r         =9;
int y         =10;
int g         =11;         

void setup() {
  Serial.begin(9600);
  pinMode(sensorLDR, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaLDR=analogRead(sensorLDR);
      bacaLDR=map(bacaLDR,0,1024,0,255);
                  //(data awal sensor,data akhir sensor,nilai yang diinginkan,nilai akhir yang diinginkan)
  
  //PRINT SERIAL
  Serial.print("Nilai LDR : ");
  Serial.println(bacaLDR);
  //Serial.print();

  //LOGIKA
  analogWrite(r,bacaLDR);
  analogWrite(y,bacaLDR);
  analogWrite(g,bacaLDR);
  



}
