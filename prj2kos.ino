#include <SPI.h> 
#include "RF24.h" 
#include "nRF24L01.h"

// Define pin numbers
const int buzzerPin = 5;
const int lm35Pin = 2; // Sensor pin
const int mq135Pin = 3;
const int mq2Pin = 4;
const int mq4Pin = 0;
const int mq7Pin = 1;

// Define data array and variables
int data[1]; // Data array for sending
int deger1[2], deger2[3], deger3[4], deger4[5]; // Sensor values
int esikDeger1 = 335, esikDeger2 = 1000, esikDeger3 = 1000, esikDeger4 = 1000; // Threshold values

// Instantiate RF24 object and define pipe address
RF24 radio(7, 8); // CE and CSN pins for RF24 library
const uint64_t pipe = 0xE8E8F0F0E1LL; // Pipe address for communication with receiver

void setup() {
  Serial.begin(9600); // Initialize serial communication for data display
  pinMode(lm35Pin, INPUT); // Set sensor pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output

  radio.begin(); // Initialize nRF24 communication
  radio.openWritingPipe(pipe); // Set receiver's address for data transmission
}

void loop() {
  // Read sensor values
  data[0] = analogRead(lm35Pin);
  deger1[2] = analogRead(mq135Pin);
  deger2[3] = analogRead(mq2Pin);
  deger3[4] = analogRead(mq4Pin);
  deger4[5] = analogRead(mq7Pin);

  // Display sensor values on serial monitor
  Serial.println(data[0]);
  Serial.println(deger1[2]);
  Serial.println(deger2[3]);
  Serial.println(deger3[4]);
  Serial.println(deger4[5]);

  // Send sensor data via nRF24
  radio.write(data, sizeof(data)); // Send data array
  radio.write(&deger1, sizeof(deger1)); // Send deger1 (mq135)
  radio.write(&deger2, sizeof(deger2)); // Send deger2 (mq2)
  radio.write(&deger3, sizeof(deger3)); // Send deger3 (mq4)
  radio.write(&deger4, sizeof(deger4)); // Send deger4 (mq7)

  // Check sensor values against threshold values and activate buzzer if exceeded
  if (*deger1 > esikDeger1) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }

  if (*deger2 > esikDeger2) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }

  if (*deger3 > esikDeger3) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }

  if (*deger4 > esikDeger4) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }

  // Check data value against threshold and activate buzzer if exceeded
  if (*data >= 500) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
}
