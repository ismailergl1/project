#include <SPI.h>  //nRF24L01 ile haberleşmek için SPI kütüphanesini ekliyoruz.ALICI
#include "RF24.h"      //nRF24L01'in ana kütüphanesi.
#include "nRF24L01.h"
#define buzzerPin 2 //Gelen datayla aktive edilecek olan komponentlerin pinlerini tanımlıyoruz.
#define threshold 500 //LM35 kullanılarak eşik değer tanımlıyoruz.
#define esikdeger1 335 //135
#define esikdeger2 1000 //2
#define esikdeger3 1000 //4
#define esikdeger4 1000 //7
int led1 = 4; //Ledin pinini tanımlıyoruz.
int data[1]; //Data isminde bir dizi tanımlıyoruz ve gönderilecek datayı belirtiyoruz.
int deger1[1]; //mq135
int deger2[1]; //mq2
int deger3[1]; //mq4
int deger4[1]; //mq7
RF24 radio(7, 8); //nRF24L modülünün CE ve CSN pinlerini tanımlıyoruz.
const uint64_t pipe = 0xE8E8F0F0E1LL; //Verici ile iletişim için pipe adresini tanımlıyoruz.
void setup() {
  pinMode(led1, OUTPUT); //Ledi output olarak tanımlıyoruz.
  Serial.begin(9600); //Seri iletişimi başlatıyoruz.
  radio.begin(); //nRF24 iletişimini başlatıyoruz.
  radio.openReadingPipe(1, pipe); //Programın data göndereceği alıcının adresini ayarlıyoruz.
  radio.startListening();
}
void loop() {
  if (radio.available()) { //Eğer iletişim uygunsa
    radio.read(data, sizeof(data)); //Gelen datayı oku
    radio.read(deger1, sizeof(deger1));
    radio.read(deger2, sizeof(deger2));
    radio.read(deger3, sizeof(deger3));
    radio.read(deger4, sizeof(deger4));
    Serial.println(data[0]); //Gelen datayı seri monitörde göster.
    Serial.println(deger1[1]);
    if (*data > threshold) { //Eğer gelen data eşik değerden yüksekse
      tone(buzzerPin, 440); //Buzzer'ı aktive et.
      digitalWrite(led1, HIGH); //Ledi aktive et.
      delay(400);
      noTone(buzzerPin);
      digitalWrite(led1, LOW);
      delay(50);
    }
    if(*deger1>esikdeger1){
      tone(buzzerPin, 440); //Buzzer'ı aktive et.
      digitalWrite(led1, HIGH); //Ledi aktive et.
      delay(400);
      noTone(buzzerPin);
      digitalWrite(led1, LOW);
      delay(50);
     }
     if(*deger2>esikdeger2){
      tone(buzzerPin, 440); //Buzzer'ı aktive et.
      digitalWrite(led1, HIGH); //Ledi aktive et.
      delay(400);
      noTone(buzzerPin);
      digitalWrite(led1, LOW);
      delay(50);
     }
     if(*deger3>esikdeger3){
      tone(buzzerPin, 440); //Buzzer'ı aktive et.
      digitalWrite(led1, HIGH); //Ledi aktive et.
      delay(400);
      noTone(buzzerPin);
      digitalWrite(led1, LOW);
      delay(50);
      }
     if(*deger4>esikdeger4){
      tone(buzzerPin, 440); //Buzzer'ı aktive et.
      digitalWrite(led1, HIGH); //Ledi aktive et.
      delay(400);
      noTone(buzzerPin);
      digitalWrite(led1, LOW);
      delay(50);
      } 
        
    
  }
}

// SimpleRx - Receiver (Alici)
//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
//#define CE_PIN 7
//#define CSN_PIN 8
//const byte thisSlaveAddress[5] = {
//  'R',
//  'x',
//  'A',
//  'A',
//  'A'
//};
//RF24 radio(CE_PIN, CSN_PIN);
//char dataReceived[10]; // Burasi vericideki dataToSend ile eslesmelidir.
//bool newData = false;
////===========
//void setup() {
//  Serial.begin(9600);
//  Serial.println("SimpleRx Baslatiliyor");
//  radio.begin();
//  radio.setDataRate(RF24_250KBPS);
//  radio.openReadingPipe(1, thisSlaveAddress);
//  radio.startListening();
//}
////=============
//void loop() {
//  getData();
//  showData();
//}
////==============
//void getData() {
//  if (radio.available()) {
//    radio.read( & dataReceived, sizeof(dataReceived));
//    newData = true;
//  }
//}
//void showData() {
//  if (newData == true) {
//    Serial.print("Veri alindi ");
//    Serial.println(dataReceived);
//    newData = false;
//  }
//}



//#include <SPI.h>  //DENEME KODU
//#include <nRF24L01.h>
//#include <RF24.h>
//#include <printf.h>
//#define CE_PIN 9
//#define CSN_PIN 10
//const byte thisSlaveAddress[5] = {
//  'R',
//  'x',
//  'A',
//  'A',
//  'A'
//};
//RF24 radio(CE_PIN, CSN_PIN);
//char dataReceived[10]; // this must match dataToSend in the TX
//bool newData = false;
//void setup() {
//  Serial.begin(9600);
//  printf_begin();
//  Serial.println("CheckConnection Starting");
//  Serial.println();
//  Serial.println("FIRST WITH THE DEFAULT ADDRESSES after power on");
//  Serial.println(" Note that RF24 does NOT reset when Arduino resets - only when power is removed");
//  Serial.println(" If the numbers are mostly 0x00 or 0xff it means that the Arduino is not");
//  Serial.println(" communicating with the nRF24");
//  Serial.println();
//  radio.begin();
//  radio.printDetails();
//  Serial.println();
//  Serial.println();
//  Serial.println("AND NOW WITH ADDRESS AAAxR 0x41 41 41 78 52 ON P1");
//  Serial.println(" and 250KBPS data rate");
//  Serial.println();
//  radio.openReadingPipe(1, thisSlaveAddress);
//  radio.setDataRate(RF24_250KBPS);
//  radio.printDetails();
//  Serial.println();
//  Serial.println();
//}
//void loop() {
//}
