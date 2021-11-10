int R=2; //Digunakan untuk variable merah
int Y=3; //Digunakan untuk variable kuning
int G=4; //Digunakan untuk variable hijau

void setup() {
  // put your setup code here, to run once:
for (int i=2; i<=4; i++){
  pinMode(i,OUTPUT);
 }
}
void loop() {
  // put your main code here, to run repeatedly:
for (int i=2; i<=4; i++){
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
  delay(1000);
 }
}
