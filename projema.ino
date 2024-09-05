
#define USE_ARDUINO_INTERRUPTS true    // Pulse kütüphanesinin daha doğru ölçüm yapabilmesi için bu ayarı etkinleştiriyoruz
#include <PulseSensorPlayground.h> //Yazının başında bilgisayarımıza kurmuş olduğumuz Pulse Playground kütüphanesini ekliyoruz.
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//
//  //Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//  #define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin) 
//   Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//  int nabiz; //İçinde dakikadaki nabzı tutacağımız değişkeni oluşturuyoruz.
//
//  const int PulseWire = 5; // Pulse sensörümüzü bağlamış olduğumuz Analog pinini belirliyoruz.
//
// int Threshold = 510; // Yazının başında belirlemiş olduğumuz eşik değerini bu değişkene atıyoruz.
//
// PulseSensorPlayground pulseSensor; //Sensörümüzü kodumuzda kullanabilmek için onu obje olarak oluşturuyoruz.
//


int buzzerPin= 10 ;
int deger2;  // mq4
int deger1;  // mq2
int deger3;  // mq135
int deger4;  // mq 7

int deger6;  // sıcaklık
int esikDegera = 450;  //A0 MQ2 Varsayılan bir değer atayın, ihtiyaca göre değiştirilebilir.
int esikDegerb = 1000;  //A1 MQ4
int esikDegerc = 300;  // A2MQ 135
int esikDegerd =  1000; // A3MQ 7 
int lm35Pin = A6;
int zaman = 50;
int sicaklik = 0 ;
int okunan_deger = 0;
float sicaklik_gerilim = 0;



void setup() {
   pinMode(buzzerPin, OUTPUT); 
  
   Serial.begin(9600);  //Bilgisayrımızla olan seri iletişimi başlatıyoruz.
  
//  pulseSensor.analogInput(PulseWire); //Pulse sensörünün bağlıu olduğu pini belirliyoruz.
// 
//  pulseSensor.setThreshold(Threshold); //Değişkene atamış olduğumuz eşik değerini uyguluyoruz.
//  // put your setup code here, to run once:
//
//   //SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
//      Serial.println(F("SSD1306 allocation failed"));
//      for(;;); // Don't proceed, loop forever
//     }
//
//  // Draw a single pixel in white
//  display.drawPixel(10, 10, WHITE);
//
//  display.display();
//  delay(2000);
//
//  display.clearDisplay();
//  
//  display.setTextSize(2); // Draw 2X-scale text
//  display.setTextColor(WHITE);
//  display.setCursor(17, 0);
//  display.println(F("Nabziniz"));
//  display.display();      // Show initial text
//  delay(100); 
//
//  if (pulseSensor.begin()) {
//    Serial.println("Pulse sensörü objesini oluşturduk.");
    
  } //Pulse sensörü başarıyla başlatılırsa bilgisayara mesaj gönderioyoruz.



void loop(){
  deger1 = analogRead(A0);//Sensörden analog değer okuyoruz.
  deger2  = analogRead(A1);
  deger3 =  analogRead(A2);
  deger4 = analogRead(A3);
//  nabiz = analogRead(A5);
//   Serial.println(sicaklik);
//   Serial.println(deger1);
//   Serial.println(deger2);
   Serial.println(deger3);
//   Serial.println(deger4); 
    Serial.println(sicaklik);
  okunan_deger = analogRead(lm35Pin);
  sicaklik = (okunan_deger / 10);
   //Serial.println(deger3);
  // put your main code here, to run repeatedly:
//    if (pulseSensor.sawStartOfBeat()) { //Eğer nabız algılarsak
//    nabiz = pulseSensor.getBeatsPerMinute(); //Dakikadaki nabzı nabiz değişkenine kaydediyoruz.

//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(WHITE);
//    display.setCursor(17, 0);
//    display.println(F("Nabziniz"));
//    display.setCursor(50, 30);
//    display.println(nabiz);
//    display.display();      // Show initial text
//    delay(100);

    
//    Serial.println("Nabız attı. ");
//    Serial.print("BPM: ");                        
//    Serial.println(nabiz-100); //Dakikdaki nabız değerini aynıo zamanda bilgisayarımıza da gönderiyoruz.
//    
    
 
//   delay(20);
  
  
 
  if(deger1 > esikDegera){           //mq2Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
    if(deger2 > esikDegerb){           //MQ4Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  } 
   if (deger3 > esikDegerc){           //MQ135
    digitalWrite(buzzerPin, HIGH); 
    delay(100);
    digitalWrite(buzzerPin,LOW);
    delay(100);
   }
   if (deger4 > esikDegerd){          //MQ7
    digitalWrite(buzzerPin, HIGH); 
    delay(100);
    digitalWrite(buzzerPin,LOW);
    delay(100);
   }
 
    if(sicaklik >= 42){
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(buzzerPin,LOW);
    delay(100);
   }    
          
   if(nabiz < 130 ){
    digitalWrite(buzzerPin,LOW);
    delay(100);
    digitalWrite(buzzerPin,HIGH);
    delay(100);
   }            
 
  
}
