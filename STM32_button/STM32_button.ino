//INISIALISASI
int r =PA1;
int y =PA2;
int g =PA3;

int b1 =PB5;
int b2 =PB6;
int b3 =PB7;

void setup() {
  // put your setup code here, to run once:
  //PIN SETUP
  Serial.begin(9600);
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);

  pinMode(PB5, INPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int kondisi1 = digitalRead (b1);
  int kondisi2 = digitalRead (b2);
  int kondisi3 = digitalRead (b3);
  //SERIAL PRINT
  Serial.print("kondisi button");
 
 
  //LOGIKA
  //BUTTON 1
  if(kondisi1 ==1){
    digitalWrite(r, HIGH);
  }else{
    digitalWrite(r, LOW);
  }
  
  //BUTTON 2
  if(kondisi2 ==1){
    digitalWrite(y, HIGH);
  }else{
    digitalWrite(y, LOW);
  }
  
  //BUTTON 3
  if(kondisi3 ==1){
    digitalWrite(g, HIGH);
  }else{
    digitalWrite(g, LOW);
  }



}
