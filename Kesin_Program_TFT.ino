// Mechatroni
 
 
 
 
 
 #include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 


#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
//const int butonOK=24;
//int butondurumOK;
//int sayacOK=0;
const int butonok = 24; /* OK Buton pin */
int sayacok = 0; /* butona basılma sayısını tutacak değişken */
int butonDurumu = 0;


const int butonA=26;  //button down 
int butondurumA;
int sayacA=0;
int butondeger=0;

#define irsensor 22  // Ir Sensor Pin
int sensordeger;
int irdurum=0;
int irsayac=0;

int ledy=40;   ///green led
int ledk=42;   ///red
int leds=44;   // yellow

const int motor_ileri=30; //Engine forward
const int motor_geri=31; //Engine Back

void setup() {
  Serial.begin(9600);
 tft.reset(); 
 tft.begin(0x9341);   /// My 2.4 Tft Adress but This hex may not be true for you..
 tft.setRotation(3);
 //////
tft.fillScreen(BLACK);
 tft.setCursor(55,20); 
  tft.setTextColor(RED);
  tft.setTextSize(12);  
  tft.print("SNS" );
  tft.setCursor(20,130); 
  tft.setTextColor(RED);
  tft.setTextSize(3);  
  tft.print("PLAZMA VE KAYNAK" );
  tft.setCursor(45,170); 
  tft.setTextColor(RED);
  tft.setTextSize(3);  
  tft.print("TEKNOLOJILERI"); 
   tft.setCursor(120,220); 
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);  
  tft.print("LOADING .");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
  delay(300);
  tft.print(".");
delay(2000);

 /////
 pinMode(motor_ileri,OUTPUT);
 pinMode(motor_geri,OUTPUT);
  pinMode(butonA,INPUT_PULLUP);
pinMode(butonok,INPUT_PULLUP);
   pinMode(ledy,OUTPUT);
   pinMode(leds,OUTPUT);
   pinMode(ledk,OUTPUT);
 
 tft.setRotation(3);
 tft.fillScreen(BLACK);
 tft.drawFastVLine(160,0 ,240, RED);
 tft.fillRect(161,0,200,30,WHITE);
 tft.setCursor(200,10);
   tft.setTextSize(2);
   tft.setTextColor(BLUE);
   tft.println("VERILER");
     
   tft.setCursor(40,20);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("250 BOBIN");
   tft.setCursor(40,65);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("350 BOBIN");
   tft.setCursor(40,110);
   tft.setTextSize(2);
   //tft.setTextColor(WHITE);
   tft.println("450 BOBIN");
   tft.setCursor(40,155);
   tft.setTextSize(2);
   //tft.setTextColor(WHITE);
   tft.println("A70 BOBIN");
   tft.setCursor(40,200);
   tft.setTextSize(2);
   //tft.setTextColor(WHITE);
   tft.println("120 BOBIN");
}

void loop() {
 
   

   butondurumA=digitalRead(butonA);
   if(butondurumA==HIGH){
    sayacA=sayacA+1;
    delay(200);
    Serial.print("sayacAA=");
        Serial.println(sayacA);
       
      }
   if(sayacA>5){
       sayacA=0;
        }
        
    butonDurumu = digitalRead(butonok);
if (butonDurumu == HIGH) {
delay(10); /* dalgalanmalar için biraz bekleyelim */
sayacok ++; /* sayaç = sayaç + 1 yani sayaç değeri bir arttırıldı */
Serial.print("Buton==");
Serial.println(sayacok); /* sayaç değerimizi ekrana yazdırıyoruz */
while(butonDurumu == HIGH){ /* Butona basili olduğu surece bekle */
butonDurumu = digitalRead(butonok); /* Butonun durumunu kontrol et */
}
delay(10); /* dalgalanmalar için biraz bekleyelim */
}
if(sayacok>1){
  sayacok=0;
  Serial.print("Buton==");
Serial.println(sayacok);
}

           
    

    
  switch(sayacA){

    case 1 :                            /////// for 250 bobin  .....
     tft.fillRect(5,200,30,225,BLACK);  
     tft.setRotation(3);
   tft.setCursor(5,20);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("->");
     if(sayacA==1 && sayacok==0){
      tft.fillRect(161,31,360,240,BLACK);
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
       digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
    if(sayacA!=1){
         tft.fillRect(161,31,360,240,BLACK);
     digitalWrite(leds,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
      digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
 if(sayacA==1 && sayacok==1){
digitalWrite(motor_ileri,HIGH);
   digitalWrite(motor_geri,LOW);
  sensordeger=digitalRead(irsensor);

if (sensordeger==0){

      if(irdurum==0){
            irsayac++;
            irdurum=1;
            Serial.print("irSayaç: ");
            Serial.println(irsayac);
               //tft.fillRect(123,80,50,23,BLACK);
               tft.setRotation(3);
   tft.setCursor(165,50);
   tft.setTextSize(2);
    tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(BLUE);
   tft.print(" CYCLE=");
   tft.println(irsayac);
             }
      delay(20);
      }
  else{
     irdurum=0; } 
     
        if(irsayac==15&&irsayac!=25){ ///-250 bobin seçeneği için--- 1. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
      tft.setCursor(165,90);
   tft.setTextSize(2);
   // tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(GREEN);
   tft.print("(1.Role=ON)"); 
   digitalWrite(ledy,HIGH);
     
     }
     if(irsayac>=20&&irsayac!=25){ ///-250 bobin seçeneği için--- 2. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı)? ,,Sağ taraftaki sayıyı ise maks sarımı giricez
   
   tft.setTextSize(2);
   tft.setCursor(165,125);
    //tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(YELLOW);
   tft.print("(2.Role=ON)");
  // digitalWrite(ledy,HIGH);
   digitalWrite(leds,HIGH);   
     }  
     if(irsayac>=25){           /////// 250 bobin toplam sarım sayısı ne olsun ?
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
   digitalWrite(ledk,HIGH);
  // digitalWrite(ledy,HIGH);
 //  digitalWrite(leds,HIGH);
   irsayac=25;
    tft.setTextSize(2);
   tft.setCursor(165,160);
    tft.setTextColor(RED);
   tft.print("(3.Role=ON)");
 tft.setCursor(180,200);
    tft.setTextColor(CYAN);
   tft.print("SARIM BITTI");
   tft.setCursor(165,225);
   tft.setTextSize(1);
    tft.setTextColor(BLUE);
   tft.print("<--Mavi Buton Menuye Don");
    }
   
     }
    // else
     //digitalWrite(ledy,LOW);
   //  digitalWrite(leds,LOW);
    // digitalWrite(ledk,LOW);
    
break;
 

case 2:
tft.fillRect(5,20,30,45,BLACK);  
tft.setRotation(3);
tft.setCursor(5,65);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("->");
     if(sayacA==2 && sayacok==0){
      tft.fillRect(161,31,360,240,BLACK);
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
       digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
    if(sayacA!=2){
         tft.fillRect(161,31,360,240,BLACK);
     digitalWrite(leds,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
      digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
 if(sayacA==2 && sayacok==1){
digitalWrite(motor_ileri,HIGH);
   digitalWrite(motor_geri,LOW);
  sensordeger=digitalRead(irsensor);

if (sensordeger==0){

      if(irdurum==0){
            irsayac++;
            irdurum=1;
            Serial.print("irSayaç: ");
            Serial.println(irsayac);
               //tft.fillRect(123,80,50,23,BLACK);
               tft.setRotation(3);
   tft.setCursor(165,50);
   tft.setTextSize(2);
    tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(BLUE);
   tft.print(" CYCLE=");
   tft.println(irsayac);
             }
      delay(20);
      }
  else{
     irdurum=0; } 
     
        if(irsayac==15&&irsayac!=25){ ///-350 bobin seçeneği için--- 1. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
      tft.setCursor(165,90);
   tft.setTextSize(2);
   // tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(GREEN);
   tft.print("(1.Role=ON)"); 
   digitalWrite(ledy,HIGH);
     
     }
     if(irsayac>=20&&irsayac!=25){ ///-350 bobin seçeneği için--- 2. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
   
   tft.setTextSize(2);
   tft.setCursor(165,125);
    //tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(YELLOW);
   tft.print("(2.Role=ON)");
  // digitalWrite(ledy,HIGH);
   digitalWrite(leds,HIGH);   
     }  
     if(irsayac>=25){           /////// 350 bobin toplam sarım sayısı ne?
    digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
   digitalWrite(ledk,HIGH);
  // digitalWrite(ledy,HIGH);
 //  digitalWrite(leds,HIGH);
   irsayac=25;
    tft.setTextSize(2);
   tft.setCursor(165,160);
    tft.setTextColor(RED);
   tft.print("(3.Role=ON)");
   tft.setCursor(180,200);
    tft.setTextColor(CYAN);
   tft.print("SARIM BITTI");
   tft.setCursor(165,225);
   tft.setTextSize(1);
    tft.setTextColor(BLUE);
   tft.print("<--Mavi Buton Menuye Don");
    }
   
     }
break;
  
 
   
   case 3:
   tft.fillRect(5,65,30,90,BLACK);
   tft.setRotation(3);
tft.setCursor(5,110);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("->");
    if(sayacA==3 && sayacok==0){
      tft.fillRect(161,31,360,240,BLACK);
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
       digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
    if(sayacA!=3){
         tft.fillRect(161,31,360,240,BLACK);
     digitalWrite(leds,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
      digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
 if(sayacA==3 && sayacok==1){
digitalWrite(motor_ileri,HIGH);
   digitalWrite(motor_geri,LOW);
  sensordeger=digitalRead(irsensor);

if (sensordeger==0){

      if(irdurum==0){
            irsayac++;
            irdurum=1;
            Serial.print("irSayaç: ");
            Serial.println(irsayac);
               //tft.fillRect(123,80,50,23,BLACK);
               tft.setRotation(3);
   tft.setCursor(165,50);
   tft.setTextSize(2);
    tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(BLUE);
   tft.print(" CYCLE=");
   tft.println(irsayac);
             }
      delay(20);
      }
  else{
     irdurum=0; } 
     
        if(irsayac==15&&irsayac!=25){///-450 bobin seçeneği için--- 1. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
      tft.setCursor(165,90);
   tft.setTextSize(2);
   // tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(GREEN);
   tft.print("(1.Role=ON)"); 
   digitalWrite(ledy,HIGH);
     
     }
     if(irsayac>=20&&irsayac!=25){ ///-450 bobin seçeneği için--- 2. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
   
   tft.setTextSize(2);
   tft.setCursor(165,125);
    //tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(YELLOW);
   tft.print("(2.Role=ON)");
  // digitalWrite(ledy,HIGH);
   digitalWrite(leds,HIGH);   
     }  
     if(irsayac>=25){           /////// 450 bobin toplam sarım sayısı ne?
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
   digitalWrite(ledk,HIGH);
  // digitalWrite(ledy,HIGH);
 //  digitalWrite(leds,HIGH);
   irsayac=25;
    tft.setTextSize(2);
   tft.setCursor(165,160);
    tft.setTextColor(RED);
   tft.print("(3.Role=ON)");
   tft.setCursor(180,200);
    tft.setTextColor(CYAN);
   tft.print("SARIM BITTI");
   tft.setCursor(165,225);
   tft.setTextSize(1);
    tft.setTextColor(BLUE);
   tft.print("<--Mavi Buton Menuye Don");
    }
   
     }
  break;
  
case 4:
   tft.fillRect(5,110,30,135,BLACK);
   tft.setRotation(3);
tft.setCursor(5,155);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("->");

    if(sayacA==4 && sayacok==0){
      tft.fillRect(161,31,360,240,BLACK);
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
       digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
    if(sayacA!=4){
         tft.fillRect(161,31,360,240,BLACK);
     digitalWrite(leds,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
      digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
 if(sayacA==4 && sayacok==1){
digitalWrite(motor_ileri,HIGH);
   digitalWrite(motor_geri,LOW);
  sensordeger=digitalRead(irsensor);

if (sensordeger==0){

      if(irdurum==0){
            irsayac++;
            irdurum=1;
            Serial.print("irSayaç: ");
            Serial.println(irsayac);
               //tft.fillRect(123,80,50,23,BLACK);
               tft.setRotation(3);
   tft.setCursor(165,50);
   tft.setTextSize(2);
    tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(BLUE);
   tft.print(" CYCLE=");
   tft.println(irsayac);
             }
      delay(20);
      }
  else{
     irdurum=0; } 
     
        if(irsayac==15&&irsayac!=25){ ///-A70 bobin seçeneği için--- 1. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
      tft.setCursor(165,90);
   tft.setTextSize(2);
   // tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(GREEN);
   tft.print("(1.Role=ON)"); 
   digitalWrite(ledy,HIGH);
     
     }
     if(irsayac>=20&&irsayac!=25){ ///-A70 bobin seçeneği için--- 2. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
   
   tft.setTextSize(2);
   tft.setCursor(165,125);
    //tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(YELLOW);
   tft.print("(2.Role=ON)");
  // digitalWrite(ledy,HIGH);
   digitalWrite(leds,HIGH);   
     }  
     if(irsayac>=25){           /////// A70 bobin toplam sarım sayısı ne?
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
   digitalWrite(ledk,HIGH);
  // digitalWrite(ledy,HIGH);
 //  digitalWrite(leds,HIGH);
   irsayac=25;
    tft.setTextSize(2);
   tft.setCursor(165,160);
    tft.setTextColor(RED);
   tft.print("(3.Role=ON)");
    tft.setCursor(180,200);
    tft.setTextColor(CYAN);
   tft.print("SARIM BITTI");
   tft.setCursor(165,225);
   tft.setTextSize(1);
    tft.setTextColor(BLUE);
   tft.print("<--Mavi Buton Menuye Don");
   
    }
   
     }
break;
  
   case 5:
   tft.fillRect(5,155,30,180,BLACK);
   tft.setRotation(3);
tft.setCursor(5,200);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("->");
    if(sayacA==5 && sayacok==0){
      tft.fillRect(161,31,360,240,BLACK);
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
       digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
    if(sayacA!=5){
         tft.fillRect(161,31,360,240,BLACK);
     digitalWrite(leds,LOW);
     irsayac=0;
      digitalWrite(ledy,LOW);
      digitalWrite(leds,LOW);
      digitalWrite(ledk,LOW);
    }
 if(sayacA==5 && sayacok==1){
digitalWrite(motor_ileri,HIGH);
   digitalWrite(motor_geri,LOW);
  sensordeger=digitalRead(irsensor);

if (sensordeger==0){

      if(irdurum==0){
            irsayac++;
            irdurum=1;
            Serial.print("irSayaç: ");
            Serial.println(irsayac);
               //tft.fillRect(123,80,50,23,BLACK);
               tft.setRotation(3);
   tft.setCursor(165,50);
   tft.setTextSize(2);
    tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(BLUE);
   tft.print(" CYCLE=");
   tft.println(irsayac);
             }
      delay(20);
      }
  else{
     irdurum=0; } 
     
        if(irsayac==15&&irsayac!=25){ /// 120 bobin seçeneği için--- 1. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
      tft.setCursor(165,90);
   tft.setTextSize(2);
   // tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(GREEN);
   tft.print("(1.Role=ON)"); 
   digitalWrite(ledy,HIGH);
     
     }
     if(irsayac>=20&&irsayac!=25){ /// 120 bobin seçeneği için--- 2. role çıkışına kacıncı sarımda ulaşsın (soldaki sayı),,,Sağ taraftaki sayıyı ise maks sarımı giricez ?
   
   tft.setTextSize(2);
   tft.setCursor(165,125);
    //tft.fillRect(247,47,60,20,BLACK);
   tft.setTextColor(YELLOW);
   tft.print("(2.Role=ON)");
  // digitalWrite(ledy,HIGH);
   digitalWrite(leds,HIGH);   
     }  
     if(irsayac>=25){           /////// 120 bobin toplam sarım sayısı ne?
      digitalWrite(motor_ileri,LOW);
   digitalWrite(motor_geri,LOW);
   digitalWrite(ledk,HIGH);
  // digitalWrite(ledy,HIGH);
 //  digitalWrite(leds,HIGH);
   irsayac=25;
    tft.setTextSize(2);
   tft.setCursor(165,160);
    tft.setTextColor(RED);
   tft.print("(3.Role=ON)");
    tft.setCursor(180,200);
    tft.setTextColor(CYAN);
   tft.print("SARIM BITTI");
   tft.setCursor(165,225);
   tft.setTextSize(1);
    tft.setTextColor(BLUE);
   tft.print("<--Mavi Buton Menuye Don");
    }
   
     }
   break;
   
   default :
 //  sayacA=5;
 tft.fillRect(5,200,30,225,BLACK);
  tft.setRotation(3);
   tft.setCursor(40,20);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("250 BOBIN");
   tft.setCursor(40,65);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("350 BOBIN");
   tft.setCursor(40,110);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("450 BOBIN");
   tft.setCursor(40,155);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("A70 BOBIN");
   tft.setCursor(40,200);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.println("120 BOBIN");
   
   break;
   }
   
   
}
