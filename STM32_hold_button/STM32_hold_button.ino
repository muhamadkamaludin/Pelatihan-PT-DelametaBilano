//INISIALISASI
int r =PA1;
int y =PA2;
int g =PA3;

int b1 =PA4;
int b2 =PA5;
int b3 =PA6;

int kunci1 =0;
int kunci2 =0;
int kunci3 =0;

//11.40 ngoding
//33.33 rangkaian
void setup() {
  // put your setup code here, to run once:
  //SETTING PIN
  Serial.begin (9600);
  pinMode (r, OUTPUT);
  pinMode (y, OUTPUT);
  pinMode (g, OUTPUT);

  pinMode (b1, INPUT);
  pinMode (b2, INPUT);
  pinMode (b3, INPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int kondisi1 = digitalRead(b1);
  int kondisi2 = digitalRead(b2);
  int kondisi3 = digitalRead(b3);
  //SERIAL PRINT
  Serial.print ("kondisi button 1");
  Serial.println (kondisi1);
  Serial.print ("kondisi button 2");
  Serial.println (kondisi2);
  Serial.print ("kondisi button 3");
  Serial.println (kondisi3);

  //LOGIKA
  //BUTTON 1
  if (kondisi1 ==1 and kunci1 ==0){
    delay(200);
    digitalWrite(r, HIGH);
    digitalWrite(y, HIGH);
    digitalWrite(g, HIGH);
    kunci1 =1;
  }else if (kondisi1 ==1 and kunci1 ==1){
    delay(200);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    kunci1 =0;
  }

//  //BUTTON 2
//  if (kondisi2 ==1 and kunci2 ==0){
//    delay(200);
//    digitalWrite(y, HIGH);
//    kunci2 =1;
//  }else if (kondisi2 ==1 and kunci2 ==1){
//    delay(200);
//    digitalWrite(y, LOW);
//    kunci2 =0;
//  }
//  //BUTTON 3
//  if (kondisi3 ==1 and kunci3 ==0){
//    delay(200);
//    digitalWrite(g, HIGH);
//    kunci3 =1;
//  }else if (kondisi3 ==1 and kunci3 ==1){
//    delay(200);
//    digitalWrite(g, LOW);
//    kunci3 =0;
//  }
}
