int R=2; //Digunakan untuk variable merah
int Y=3; //Digunakan untuk variable kuning
int G=4; //Digunakan untuk variable hijau

void setup() {
  // put your setup code here, to run once:
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(R,HIGH);
delay(1000);
digitalWrite(R,LOW);
delay(1000);
digitalWrite(Y,HIGH);
delay(1000);
digitalWrite(Y,LOW);
delay(1000);
digitalWrite(G,HIGH);
delay(2000);
digitalWrite(G,LOW);
delay(2000);
}
