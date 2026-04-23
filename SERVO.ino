#include <Servo.h>
#include <TouchScreen.h>

// Touch pins
#define YP A3
#define XM A2
#define YM A4
#define XP A1

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Servo
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(4);  // servo pin
}

void loop() {
  TSPoint p = ts.getPoint();

  // Restore pin modes after reading touch
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > 100 && p.z < 1000) { // valid touch
    Serial.print("X: "); Serial.print(p.x);
    Serial.print(" Y: "); Serial.println(p.y);

    // SIMPLE control zones (adjust later if needed)
    if (p.x < 300) {
      myservo.write(0);
    } 
    else if (p.x < 700) {
      myservo.write(90);
    } 
    else {
      myservo.write(180);
    }

    delay(050); // debounce
  }
}





