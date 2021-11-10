///Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
int buzzer =7;
int ir =2;
String uidString;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 pinMode(buzzer, OUTPUT);
 pinMode(ir, INPUT);
 
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( mfrc522.PICC_IsNewCardPresent()) {
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
 if (uidString=="5_8F_8E_BF"){
    bunyibuzzeroke();
    Serial.println("Silahkan Masuk");
 }else if (uidString=="A_A8_90_15"){
    bunyibuzzeroke();
    Serial.println("Silahkan Masuk");
  }else{
    Serial.println("GAGAL");
    bunyibuzzergagal();
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
