
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

int mode = 6;

int tiltX = 8;
int tiltY = 7;

char arrowDown = 25;
char arrowRight = 26;
char arrowFilledLeft = 17;
char arrowFilledRight = 16;
char arrowFilledUp = 30;
char arrowFilledDown = 31;
char arrowLeft = 27;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(INPUT, tiltX);
  pinMode(INPUT, tiltY);
  pinMode(INPUT, mode);
}

void loop() {

  display.clearDisplay();
  Serial.println(digitalRead(mode));

  if (digitalRead(tiltY) == HIGH && digitalRead(mode) == LOW){
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(arrowFilledUp);

    display.setTextSize(2);
    display.setCursor(0, 50);
    display.print(arrowFilledDown);

    display.setTextSize(4);
    display.setCursor(55, 20);
    display.print(arrowDown);
    display.display();
    delay(200);

  }

  else if(digitalRead(tiltY) == LOW && digitalRead(mode) == LOW){
    display.setTextSize(2);
    display.setCursor(50, 25);
    display.print("OK");
    display.display(); 
    delay(200);

  }

  else if(digitalRead(tiltX) == LOW && digitalRead(tiltY) == HIGH && digitalRead(mode) == HIGH){

    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(arrowFilledLeft);

    display.setTextSize(2);
    display.setCursor(110, 0);
    display.print(arrowFilledRight);

    display.setTextSize(5);
    display.setCursor(50, 20);
    display.print(arrowRight);
    display.display(); 
    delay(200);
  }

  else if(digitalRead(tiltX) == HIGH && digitalRead(tiltY) == HIGH && digitalRead(mode) == HIGH){
    display.setTextSize(2);
    display.setCursor(50, 25);
    display.print("OK");
    display.display(); 
    delay(200);
  }

    else if(digitalRead(tiltX) == LOW && digitalRead(tiltY) == LOW && digitalRead(mode) == HIGH){

    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(arrowFilledLeft);

    display.setTextSize(2);
    display.setCursor(110, 0);
    display.print(arrowFilledRight);

    display.setTextSize(5);
    display.setCursor(50, 20);
    display.print(arrowLeft);
    display.display(); 
    delay(200);


  }

  else if(digitalRead(tiltX) == HIGH && digitalRead(tiltY) == LOW && digitalRead(mode) == HIGH){

    display.setTextSize(2);
    display.setCursor(50, 25);
    display.print("OK");
    display.display(); 
    delay(200);
  }

  else{
    display.setTextSize(2);
    display.setCursor(40, 30);
    display.print("ERROR");
    display.display(); 
    delay(200);
  }

}
