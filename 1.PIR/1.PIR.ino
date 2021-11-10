//INISIALISASI 
int sensorPIR =2;
int buzzer    =5;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPIR, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaPIR=digitalRead(sensorPIR);
  
  //PRINT SERIAL
  Serial.print("Nilai PIR : ");
  Serial.println(bacaPIR);
  //Serial.print();

  //LOGIKA
  if(bacaPIR ==1){
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(50);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(50);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(50);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(1000);
  }else{
    if(bacaPIR ==0){
      digitalWrite(buzzer,LOW);
    }
    
  }

}
