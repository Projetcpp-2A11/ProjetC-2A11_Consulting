#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <MFRC522.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// RFID setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// For receiving consultant info from PC
String oledLines[4];
int lineIdx = 0;

void setup() {
  Serial.begin(9600);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Welcome");
  display.display();
  delay(1500);
  display.clearDisplay();
  display.display();

  // RFID init
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // 1. Handle consultant info from PC (for OLED)
  while (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();
    if (line == "END") {
      // Display all lines and reset for next message
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      for (int i = 0; i < lineIdx; i++) {
        display.println(oledLines[i]);
      }
      display.display();
      delay(5000); // Hold the info for 5 seconds (change as desired)
      display.clearDisplay();
      display.display();
      lineIdx = 0;
    } else if (line.length() > 0 && lineIdx < 4) {
      oledLines[lineIdx++] = line;
    }
  }

  // 2. Handle RFID reading (show UID in Serial Monitor)
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Card UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
    mfrc522.PICC_HaltA();
  }
}