int R=2; //Digunakan untuk variable merah
int Y=3; //Digunakan untuk variable kuning
int G=4; //Digunakan untuk variable hijau

void setup() {
  Serial.begin(9600);
for (int i=2; i<=6; i++){
  pinMode(i,OUTPUT);
 }
}
void loop() {
  
for (int i=0; i<=255; i++){
analogWrite(3,i);
float volt=(5.0/255.0);
float ia = i*volt;
Serial.println("volt : " + String(ia) + " v ");
delay(20);
 }
for (int i=255; i>=0; i--){
analogWrite(3,i);
float volt=(5.0/255.0);
float ia = i*volt;
Serial.println("volt : " + String(ia) + " v ");
delay(20);
}
for (int i=0; i<=255; i++){
analogWrite(5,i);
delay(20);
}
for (int i=255; i>=0; i--){
analogWrite(5,i);
delay(20);
}
for (int i=0; i<=255; i++){
analogWrite(6,i);
delay(20);
}
for (int i=255; i>=0; i--){
analogWrite(6,i);
delay(20);
}
}
