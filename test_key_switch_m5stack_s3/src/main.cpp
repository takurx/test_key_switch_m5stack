#include <Arduino.h>
#include <M5Unified.h>
#include <USB.h>
#include <USBHIDKeyboard.h>

USBHIDKeyboard Keyboard;

bool buttonAPressed = false;
bool buttonBPressed = false;
bool buttonCPressed = false;

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);
  
  M5.Display.setTextSize(2);
  M5.Display.setTextColor(WHITE);
  M5.Display.fillScreen(BLACK);
  M5.Display.setCursor(10, 10);
  M5.Display.println("USB HID Keyboard");
  M5.Display.setCursor(10, 40);
  M5.Display.println("A: 'A'");
  M5.Display.setCursor(10, 70);
  M5.Display.println("B: '😆'");
  M5.Display.setCursor(10, 100);
  M5.Display.println("C: '🍭✒'");
  
  Serial.begin(115200);
  Serial.println("Starting USB HID Keyboard...");
  
  // Initialize USB HID Keyboard
  Keyboard.begin();
  USB.begin();
  
  M5.Display.setCursor(10, 140);
  M5.Display.println("Ready!");
}

void loop() {
  M5.update();
  
  // Button A pressed
  if(M5.BtnA.wasPressed() && !buttonAPressed) {
    buttonAPressed = true;
    Keyboard.print("A");
    Serial.println("Button A pressed - sent 'A'");
    
    // Visual feedback
    M5.Display.fillRect(10, 170, 300, 30, GREEN);
    M5.Display.setTextColor(BLACK);
    M5.Display.setCursor(10, 175);
    M5.Display.println("A pressed!");
    delay(200);
    M5.Display.fillRect(10, 170, 300, 30, BLACK);
    M5.Display.setTextColor(WHITE);
  }
  
  // Button B pressed
  if(M5.BtnB.wasPressed() && !buttonBPressed) {
    buttonBPressed = true;
    Keyboard.print("😆");
    Serial.println("Button B pressed - sent '😆'");
    
    // Visual feedback
    M5.Display.fillRect(10, 170, 300, 30, BLUE);
    M5.Display.setTextColor(WHITE);
    M5.Display.setCursor(10, 175);
    M5.Display.println("B pressed!");
    delay(200);
    M5.Display.fillRect(10, 170, 300, 30, BLACK);
  }
  
  // Button C pressed
  if(M5.BtnC.wasPressed() && !buttonCPressed) {
    buttonCPressed = true;
    Keyboard.print("🍭✒");
    Serial.println("Button C pressed - sent '🍭✒'");
    
    // Visual feedback
    M5.Display.fillRect(10, 170, 300, 30, RED);
    M5.Display.setTextColor(WHITE);
    M5.Display.setCursor(10, 175);
    M5.Display.println("C pressed!");
    delay(200);
    M5.Display.fillRect(10, 170, 300, 30, BLACK);
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
  
  // Update status
  M5.Display.fillRect(10, 210, 300, 20, BLACK);
  M5.Display.setTextColor(GREEN);
  M5.Display.setCursor(10, 210);
  M5.Display.println("USB HID Ready");
  
  delay(50);
}
