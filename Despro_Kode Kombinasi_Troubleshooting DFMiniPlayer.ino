#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Initialize LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 chars, 2 lines

// Initialize glex sensors
const int flexPin0 = A0;
const int flexPin1 = A1;
const int flexPin2 = A2;

// DFPlayer Mini setup
DFRobotDFPlayerMini myDFPlayer;
SoftwareSerial mySoftwareSerial(9, 10);
bool isDFPlayerOnline = false; // DFPlayer status

unsigned int f0, f1, f2; 

void setup() {
  // Initialize the Serial Communication
  Serial.begin(9600);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();
  
  Serial.println(F("Flex Sensor Test Initialized."));
  Serial.println(F("\ni2c scanner."));
  scrollText(F("Sensor Test Start"));
  delay(100);
  lcd.clear();

  // DFPlayer Mini initialization
  mySoftwareSerial.begin(9600);
  Serial.println(F("Initializing DFPlayer..."));
  
  if (myDFPlayer.begin(mySoftwareSerial)) {
    isDFPlayerOnline = true; // Set to true if DFPlayer is online
    Serial.println(F("DFPlayer Mini online."));
    myDFPlayer.volume(30);  // Set volume (0-30) 
  } else {
    Serial.println(F("DFPlayer Mini not found. Skipping audio functionality."));
    isDFPlayerOnline = false; // Set to false if DFPlayer is offline
  }
}

void loop() {
  // Read the vakue of flex sensor
  f0 = analogRead(flexPin0);
  f1 = analogRead(flexPin1);
  f2 = analogRead(flexPin2);

  // Clear the LCD before displaying a new message
  lcd.clear();

  // Print the value to Serial Monitor
  Serial.print("Flex Sensor 0: ");
  Serial.println(f0);
  Serial.print("Flex Sensor 1: ");
  Serial.println(f1);
  Serial.print("Flex Sensor 2: ");
  Serial.println(f2);

  // Pick the maximum value of the flex sensor
  unsigned int maxVal = max(f0, max(f1, f2));

  // Check if minimum value met
  if (maxVal >= 960){ 
  // Check conditions and print messages
  if (maxVal == f2 && f2 <= 970) {
    Serial.println("Saya Butuh Bantuan");
    lcd.clear();
    lcd.setCursor(0, 0);
    scrollText(F("Saya Butuh Bantuan"));
    if (isDFPlayerOnline) myDFPlayer.playFolder(1, 1); // Play audio only if DFPlayer is online
        // myDFPlayer.play(1); // track 1

    delay(1000);
  } else if (maxVal == f1 && f1 >= 980) {
    Serial.println("Saya Butuh Air");
    lcd.clear();
    lcd.setCursor(0, 0);
    scrollText(F("Saya Butuh Air"));
    if (isDFPlayerOnline) myDFPlayer.playFolder(2, 2); // Play audio only if DFPlayer is online
        // myDFPlayer.play(2); // track 1

    delay(1000);
  } else if (maxVal == f1 && f1 <= 978) {
    Serial.println("Saya Butuh Makan");
    lcd.clear();
    lcd.setCursor(0, 0);
    scrollText(F("Saya Butuh Makan"));
    if (isDFPlayerOnline) myDFPlayer.playFolder(3, 3); // Play audio only if DFPlayer is online
        // myDFPlayer.play(3); // track 3

    delay(1000);
  } else if (maxVal == f2 && f2 >= 980) {
    Serial.println("Saya Mau Ke Toilet");
    lcd.clear();
    lcd.setCursor(0, 0);
    scrollText(F("Saya Mau ke toilet"));
    if (isDFPlayerOnline) myDFPlayer.playFolder(4, 4); // Play audio only if DFPlayer is online
        // myDFPlayer.play(4); // Folder 1, track 1

    delay(1000);
  } else if (maxVal == f0 && f0 < 977) {
    Serial.println("Saya Butuh Dokter");
    lcd.clear();
    lcd.setCursor(0, 0);
    scrollText(F("Saya Butuh Dokter"));
    if (isDFPlayerOnline) myDFPlayer.playFolder(5, 5); // Play audio only if DFPlayer is online
        // myDFPlayer.play(5); // Folder 1, track 1

    delay(1000);
  }

  // add delay before the next loop
  delay(2000);
}
  // add delay before the next loop
  delay(2000);
}

// Function to display scrolling text
void scrollText(String message) {
  int len = message.length();
  for (int i = 0; i < len; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message.substring(i, min(i + 16, len))); // Print part of the message
    delay(200); // Adjust the delay for scroll speed
  }
}
