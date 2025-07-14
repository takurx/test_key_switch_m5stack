#include <Arduino.h>
#include <M5Stack.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("M5Stack Keyboard", "M5Stack", 100);

bool buttonAPressed = false;
bool buttonBPressed = false;
bool buttonCPressed = false;

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.println("BLE Keyboard");
  M5.Lcd.setCursor(10, 40);
  M5.Lcd.println("A: 'A'");
  M5.Lcd.setCursor(10, 70);
  M5.Lcd.println("B: ':smile:'");
  M5.Lcd.setCursor(10, 100);
  M5.Lcd.println("C: ':lollipop::black_nib:'");
  
  Serial.begin(115200);
  Serial.println("Starting BLE Keyboard...");
  
  bleKeyboard.begin();
  
  M5.Lcd.setCursor(10, 140);
  M5.Lcd.println("Ready!");
}

void loop() {
  M5.update();
  
  // Check if BLE keyboard is connected
  if(bleKeyboard.isConnected()) {
    // Button A pressed
    if(M5.BtnA.wasPressed() && !buttonAPressed) {
      buttonAPressed = true;
      bleKeyboard.print("A");
      Serial.println("Button A pressed - sent 'A'");
      
      // Visual feedback
      M5.Lcd.fillRect(10, 170, 300, 30, GREEN);
      M5.Lcd.setTextColor(BLACK);
      M5.Lcd.setCursor(10, 175);
      M5.Lcd.println("A pressed!");
      delay(200);
      M5.Lcd.fillRect(10, 170, 300, 30, BLACK);
      M5.Lcd.setTextColor(WHITE);
    }
    
    // Button B pressed
    if(M5.BtnB.wasPressed() && !buttonBPressed) {
      buttonBPressed = true;
      // US keyboard layout
      // bleKeyboard.print(":smile:");
      // JP keyboard layout
      bleKeyboard.print("'smile'");
      Serial.println("Button B pressed - sent ':smile:'");
      
      // Visual feedback
      M5.Lcd.fillRect(10, 170, 300, 30, BLUE);
      M5.Lcd.setTextColor(WHITE);
      M5.Lcd.setCursor(10, 175);
      M5.Lcd.println("B pressed!");
      delay(200);
      M5.Lcd.fillRect(10, 170, 300, 30, BLACK);
    }
    
    // Button C pressed
    if(M5.BtnC.wasPressed() && !buttonCPressed) {
      buttonCPressed = true;
      // :lollipop:, ::black_nib:
      // US keyboard layout
      // bleKeyboard.print(":lollipop::black_nib:");
      // JP keyboard layout
      bleKeyboard.print("'lollipop''black_nib'");
      // -> :lollipop::black=nib:
      Serial.println("Button C pressed - sent ':lollipop::black_nib:'");
      
      // Visual feedback
      M5.Lcd.fillRect(10, 170, 300, 30, RED);
      M5.Lcd.setTextColor(WHITE);
      M5.Lcd.setCursor(10, 175);
      M5.Lcd.println("C pressed!");
      delay(200);
      M5.Lcd.fillRect(10, 170, 300, 30, BLACK);
    }
    
    // Reset button states when released
    if(M5.BtnA.wasReleased()) {
      buttonAPressed = false;
    }
    if(M5.BtnB.wasReleased()) {
      buttonBPressed = false;
    }
    if(M5.BtnC.wasReleased()) {
      buttonCPressed = false;
    }
    
    // Update connection status
    M5.Lcd.fillRect(10, 210, 300, 20, BLACK);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.setCursor(10, 210);
    M5.Lcd.println("BLE Connected");
  } else {
    // Not connected
    M5.Lcd.fillRect(10, 210, 300, 20, BLACK);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setCursor(10, 210);
    M5.Lcd.println("BLE Disconnected");
  }
  
  delay(50);
}
