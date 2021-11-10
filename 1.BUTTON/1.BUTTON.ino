//Inisialisasi pembuatan variable
//BUTTON
int butt = 2;
int butt2 = 3;
int butt3 = 4;
//LED
int r=5;
int y=6;
int g=7;
int x=1000;


void setup() {
//SERIAL SETTING PIN
 Serial.begin(9600);
 pinMode(r,OUTPUT);
 pinMode(y,OUTPUT);
 pinMode(g,OUTPUT);
 pinMode(butt,INPUT);
 pinMode(butt2,INPUT);
 pinMode(butt3,INPUT);
 }

void loop() {
   //prgram yang akan dijalankan berulang ulang
   //BACA DATA
   int kondisi = digitalRead (butt);
   int kondisi2 = digitalRead (butt2);
   int kondisi3 = digitalRead (butt3);
   //SERIAL PRINT
   Serial.print("kondisi button : ");
   Serial.println(kondisi);
   
   //LOGIKA
   //START BUTTON 1
   if(kondisi ==1){digitalWrite(r, HIGH);}else{digitalWrite(r, LOW);}
   //STOP BUTTON 1
   
   //START BUTTON 2
   if(kondisi2 == 1){digitalWrite(y, HIGH);}else{digitalWrite(y, LOW);}
   //STOP BUTTON 2
   
   //START BUTTON 3
   if(kondisi3 == 1){digitalWrite(g, HIGH);}else{digitalWrite(g, LOW);}
   //STOP BUTTON 3
}
