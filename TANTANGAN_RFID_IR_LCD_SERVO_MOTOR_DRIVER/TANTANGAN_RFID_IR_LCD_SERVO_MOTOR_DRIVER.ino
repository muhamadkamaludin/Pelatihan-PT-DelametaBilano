///Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
#define A1 5 //motor A pin
#define A2 6
MFRC522 mfrc522(SS_PIN, RST_PIN); 
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo;
int buzzer =7;
int ir =2;
int outservo =6;
int incomingByte = 0; // for incoming serial data
int input = 0;
String uidString;



void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 lcd.begin();
  myservo.attach(outservo);
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 pinMode(buzzer, OUTPUT);
 pinMode(ir, INPUT);
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);

 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 
 
 Serial.println("Silahkan Pilih salah satu:");
 Serial.println("1.forward");
 Serial.println("2.backward");
 Serial.println("3.stop"); 

 lcd.clear();
 lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
 lcd.setCursor(0,1);lcd.print("GERBANG TERTUTUP");
 myservo.write(0);
  digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 
 
 if ( mfrc522.PICC_IsNewCardPresent()) {
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    
    
 if (uidString=="5_8F_8E_BF" or uidString=="4A_51_6E_AE"){
    
    bunyibuzzeroke();
    lcd.clear();//Untuk menghapus karakter pada LCD
    lcd.setCursor(0,0);lcd.print(" BERHASIL ");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);lcd.print("GERBANG TERBUKA ");
    delay(1000);
    lcd.clear();
    Serial.println("Silahkan Masuk Gerbang Terbuka");
    analogWrite(A1, 255);
    analogWrite(A2, 0);
    delay(100); //Jeda waktu perulagan seama 500 mili detik
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    while(1){
      int state=digitalRead(ir);
      if (state==1){
        state=1;
      }
    else{
    
//    lcd.clear();
//    lcd.setCursor(0,1);lcd.print("TERTUTUP ");
//    delay(1000);
//    lcd.clear();
    Serial.println("GERBANG TERTUTUP");
//    lcd.clear();
//    lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
//    lcd.setCursor(0,1);lcd.print("GERBANG TERTUTUP");
    analogWrite(A1, 0);
    analogWrite(A2, 255);
       //backward
//    digitalWrite(A1, HIGH);
//    digitalWrite(A2, LOW);
    delay(100);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    break;
    }
  }
 }


else {
   bunyibuzzergagal();
   Serial.println("ga terdaftar");
   Serial.println("pintu tertutup");
   lcd.clear();//Untuk menghapus karakter pada LCD
   lcd.setCursor(0,0);lcd.print("TIDAK TERDAFTAR ");
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
   lcd.setCursor(0,1);lcd.print("GERBANG TERTUTUP");
}

}
}

void readRFID() {
  mfrc522.PICC_ReadCardSerial();

  uidString = String(mfrc522.uid.uidByte[0],HEX) + "_" +
              String(mfrc522.uid.uidByte[1],HEX) + "_" +
              String(mfrc522.uid.uidByte[2],HEX) + "_" +
              String(mfrc522.uid.uidByte[3],HEX);
  uidString.toUpperCase();
}

void bunyibuzzeroke(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(50);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(50);
}
