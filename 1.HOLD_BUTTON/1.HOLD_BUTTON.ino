//Inisialisasi pembuatan variable
//BUTTON
int butt = 2;
int butt2 = 3;
int butt3 = 4;
int kunci1 = 0;
int kunci2 = 0;
int kunci3 = 0;
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
   if(kondisi ==1 && kunci1 ==0){delay (200);digitalWrite(r, HIGH);kunci1=1;} else if(kondisi ==1 && kunci1 ==1){delay (200);digitalWrite(r, LOW);kunci1=0;}
   //STOP BUTTON 1

    //START BUTTON 2
   if(kondisi2 ==1 && kunci2 ==0){delay (200);digitalWrite(y, HIGH);kunci2=1;} else if(kondisi2 ==1 && kunci2 ==1){delay (200);digitalWrite(y, LOW);kunci2=0;}
   //STOP BUTTON 2

    //START BUTTON 3
   if(kondisi3 ==1 && kunci3 ==0){delay (200);digitalWrite(g, HIGH);kunci3=1;} else if(kondisi3 ==1 && kunci3 ==1){delay (200);digitalWrite(g, LOW);kunci3=0;}
   //STOP BUTTON 3
   
   
}
