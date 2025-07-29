#include <Arduino.h>
#include <M5Unified.h>
#include <USB.h>
#include <USBHIDKeyboard.h>

USBHIDKeyboard Keyboard;

bool buttonAPressed = false;
bool buttonBPressed = false;
bool buttonCPressed = false;

void drawTouchButtons() {
  // Draw touch button areas
  M5.Display.fillRect(0, 200, 80, 40, DARKGREY);
  M5.Display.fillRect(80, 200, 80, 40, DARKGREY);
  M5.Display.fillRect(160, 200, 80, 40, DARKGREY);
  
  // Draw button borders
  M5.Display.drawRect(0, 200, 80, 40, WHITE);
  M5.Display.drawRect(80, 200, 80, 40, WHITE);
  M5.Display.drawRect(160, 200, 80, 40, WHITE);
  
  // Draw button labels
  M5.Display.setTextColor(WHITE);
  M5.Display.setTextSize(2);
  M5.Display.setCursor(30, 215);
  M5.Display.println("A");
  M5.Display.setCursor(110, 215);
  M5.Display.println("B");
  M5.Display.setCursor(190, 215);
  M5.Display.println("C");
}

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);
  
  M5.Display.setTextSize(2);
  M5.Display.setTextColor(WHITE);
  M5.Display.fillScreen(BLACK);
  M5.Display.setCursor(10, 10);
  M5.Display.println("USB HID Keyboard");
  M5.Display.setCursor(10, 40);
  M5.Display.println("Touch Areas:");
  M5.Display.setCursor(10, 70);
  M5.Display.println("A: 'A'");
  M5.Display.setCursor(10, 100);
  M5.Display.println("B: '😆'");
  M5.Display.setCursor(10, 130);
  M5.Display.println("C: '🍭✒'");
  
  Serial.begin(115200);
  Serial.println("Starting USB HID Keyboard...");
  
  // Initialize USB HID Keyboard
  Keyboard.begin();
  USB.begin();
  
  // Draw touch buttons
  drawTouchButtons();
  
  M5.Display.setCursor(10, 160);
  M5.Display.println("Ready!");
}

void loop() {
  M5.update();
  
  // Check for touch input
  auto touch = M5.Touch.getDetail();
  if (touch.wasPressed()) {
    int x = touch.x;
    int y = touch.y;
    
    Serial.printf("Touch detected at x=%d, y=%d\n", x, y);
    
    if (x < 80 && y > 200) {
      // A button area
      if (!buttonAPressed) {
        buttonAPressed = true;
        Keyboard.print("A");
        Serial.println("Touch A area - sent 'A'");
        
        // Visual feedback
        M5.Display.fillRect(0, 200, 80, 40, GREEN);
        M5.Display.setTextColor(BLACK);
        M5.Display.setCursor(30, 215);
        M5.Display.println("A");
        delay(200);
        drawTouchButtons();
      }
    }
    else if (x >= 80 && x < 160 && y > 200) {
      // B button area
      if (!buttonBPressed) {
        buttonBPressed = true;
        // Keyboard.print("😆");
        // Keyboard.print(":smile:");  // for US keyboard layout
        Keyboard.print("'smile'");  // for JP keyboard layout
        Serial.println("Touch B area - sent '😆'");
        
        // Visual feedback
        M5.Display.fillRect(80, 200, 80, 40, BLUE);
        M5.Display.setTextColor(WHITE);
        M5.Display.setCursor(110, 215);
        M5.Display.println("B");
        delay(200);
        drawTouchButtons();
      }
    }
    else if (x >= 160 && y > 200) {
      // C button area
      if (!buttonCPressed) {
        buttonCPressed = true;
        
        // fail, try1 with JP keyboard layout
        //Keyboard.print("🍭✒");

        // fail, try2 with JP keyboard layout
        //Keyboard.print("'black_nib'");
        // -> :lollipop::black=nib:

        // patern1, for US keyboard layout
        // Keyboard.print(":lollipop:");  // for US keyboard layout
        // Keyboard.print(":black");  // for US keyboard layout
        // Keyboard.press(KEY_LEFT_SHIFT); // Press Left Shift
        // Keyboard.write(0x2D); // US keyboard layoutでは'_', JP keyboard layoutでは '='
        // Keyboard.release(KEY_LEFT_SHIFT); // Release Left Shift
        // Keyboard.print("nib:");  
        
        // patern2, for US keyboard layout
        Keyboard.print(":lollipop:");  // for US keyboard layout
        Keyboard.print(":black_nib:");  // for US keyboard layout
        
        // patern3, for JP keyboard layout
        // Keyboard.print("'lollipop'");  // for JP keyboard layout
        // Keyboard.print("'black_nib'");  // for JP keyboard layout
        // -> :lollipop::black=nib:

        Serial.println("Touch C area - sent '🍭✒'");
        
        // Visual feedback
        M5.Display.fillRect(160, 200, 80, 40, RED);
        M5.Display.setTextColor(WHITE);
        M5.Display.setCursor(190, 215);
        M5.Display.println("C");
        delay(200);
        drawTouchButtons();
      }
    }
  }
  
  // Reset button states when touch is released
  if (touch.wasReleased()) {
    buttonAPressed = false;
    buttonBPressed = false;
    buttonCPressed = false;
  }
  
  // Update status
  M5.Display.fillRect(10, 180, 200, 15, BLACK);
  M5.Display.setTextColor(GREEN);
  M5.Display.setTextSize(1);
  M5.Display.setCursor(10, 180);
  M5.Display.println("USB HID Ready");
  
  delay(50);
}
