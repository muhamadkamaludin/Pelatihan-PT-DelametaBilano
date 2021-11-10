//Inisialisasi pembuatan variable
//BUTTON
int ir = 2;
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
 pinMode(ir,INPUT);
 pinMode(butt2,INPUT);
 pinMode(butt3,INPUT);
 }

void loop() {
   //prgram yang akan dijalankan berulang ulang
   //BACA DATA
   int kondisi = 0;
   kondisi = digitalRead (ir);
   int kondisi2 = digitalRead (butt2);
   int kondisi3 = digitalRead (butt3);
   //SERIAL PRINT
   Serial.print("kondisi button : ");
   Serial.println(kondisi);
   
   //LOGIKA
 
   //START BUTTON 1
   if(kondisi ==1 && kunci1 ==0){delay (200);digitalWrite(r, LOW);kunci1=1;} else if(kondisi ==1 && kunci1 ==1){delay (200);digitalWrite(r, HIGH);kunci1=0;}
   //STOP BUTTON 1

  
   
   
}
