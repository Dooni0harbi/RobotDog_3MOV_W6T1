#include <Servo.h>

Servo frontLeft;
Servo frontRight;
Servo rearRight;
Servo rearLeft;

// Pins
const int FL_PIN = 11;
const int FR_PIN = 10;
const int RR_PIN = 9;
const int RL_PIN = 8;

// وضع الجلوس
const int REAR_RIGHT_SIT = 150;
const int REAR_LEFT_SIT  = 30;

// رفع اليدين
const int RIGHT_UP = 150;
const int LEFT_UP  = 30;

void setup() {

  frontLeft.attach(FL_PIN);
  frontRight.attach(FR_PIN);
  rearRight.attach(RR_PIN);
  rearLeft.attach(RL_PIN);

  // أول ما يبدأ الكود: كل الأرجل 90
  frontLeft.write(90);
  frontRight.write(90);
  rearRight.write(90);
  rearLeft.write(90);

  delay(2000);

  // بعدها يجلس
  sitDown();

  delay(1000);
}

void loop() {

  // يرقص وهو جالس
  // اليد اليمين تطلع
  for (int pos = 90; pos <= RIGHT_UP; pos++) {
    frontRight.write(pos);
    delay(15);
  }

  delay(250);

  // اليد اليمين تنزل
  for (int pos = RIGHT_UP; pos >= 90; pos--) {
    frontRight.write(pos);
    delay(15);
  }

  delay(200);

  // اليد اليسار تطلع
  for (int pos = 90; pos >= LEFT_UP; pos--) {
    frontLeft.write(pos);
    delay(15);
  }

  delay(250);

  // اليد اليسار تنزل
  for (int pos = LEFT_UP; pos <= 90; pos++) {
    frontLeft.write(pos);
    delay(15);
  }

  delay(200);
}


// الجلوس
void sitDown() {

  // الخلف يمين 90 -> 150
  // الخلف يسار 90 -> 30
  for (int step = 0; step <= 60; step++) {

    rearRight.write(90 + step);
    rearLeft.write(90 - step);

    delay(20);
  }

  // يثبت جالس
  rearRight.write(REAR_RIGHT_SIT);
  rearLeft.write(REAR_LEFT_SIT);

  frontRight.write(90);
  frontLeft.write(90);
}