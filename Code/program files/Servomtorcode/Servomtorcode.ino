#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int buttonPin = 2;
int goal = 0;
int buttonState;
int lastButtonState = HIGH;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  showGoal();
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && lastButtonState == HIGH) {
    goal++;
    showGoal();
    delay(200);
  }

  lastButtonState = buttonState;
}

void showGoal() {

  display.clearDisplay();

  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(20,5);
  display.println("GOALS");

  display.setTextSize(5);
  display.setCursor(45,30);
  display.println(goal);

  display.display();
}