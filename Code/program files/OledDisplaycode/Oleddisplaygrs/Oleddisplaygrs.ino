#include <U8glib.h>

// OLED setup
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

// push button pin
int buttonPin = 2;

int goals = 0;
int lastButtonState = HIGH;

void draw() {

  // Title
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr(40,15,"GOALS");

  // Big number
  char goalStr[5];
  sprintf(goalStr, "%d", goals);

  u8g.setFont(u8g_font_fub30);   // Large font
  u8g.drawStr(40,60, goalStr);
}

void setup() {

  pinMode(buttonPin, INPUT_PULLUP); // button with internal pullup
}

void loop() {

  int buttonState = digitalRead(buttonPin);

  // detect button press
  if(buttonState == LOW && lastButtonState == HIGH){
    goals++;
    delay(200); // debounce
  }

  lastButtonState = buttonState;

  // OLED display
  u8g.firstPage();
  do {
    draw();
  } while(u8g.nextPage());
}