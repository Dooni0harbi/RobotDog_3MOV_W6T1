#include <Servo.h>

Servo frontLeft;
Servo frontRight;
Servo rearRight;
Servo rearLeft;

// Pins
const int FL_PIN = 11;  // قدام يسار
const int FR_PIN = 10;  // قدام يمين
const int RR_PIN = 9;   // ورا يمين
const int RL_PIN = 8;   // ورا يسار

// مدى الرقص
const int MIN_ANGLE = 85;
const int MAX_ANGLE = 95;

// تعديل اليد الأمامية اليمين
// لأنها مرفوعة أكثر من الباقي
const int FR_OFFSET = -5;

// هاي فايف
const int RIGHT_HIGH_FIVE = 150;
const int LEFT_HIGH_FIVE  = 30;


// نخزن آخر وضع للرجلين
int lastFront = 90;
int lastRear  = 90;


void setup() {

  frontLeft.attach(FL_PIN);
  frontRight.attach(FR_PIN);
  rearRight.attach(RR_PIN);
  rearLeft.attach(RL_PIN);

  // وضع البداية
  frontLeft.write(90);

  // اليمين الأمامية أقل 5 درجات
  frontRight.write(90 + FR_OFFSET);

  rearRight.write(90);
  rearLeft.write(90);

  delay(2000);
}


void loop() {

  // =========================
  // 1) رقص 5 ثواني
  // =========================
  dance(5000);

  // =========================
  // 2) يوقف تماماً
  // =========================
  stopMovement();

  delay(1000);

  // =========================
  // 3) هاي فايف يمين
  // =========================
  highFiveRight();


  // =========================
  // 4) رقص 5 ثواني
  // =========================
  dance(5000);


  // =========================
  // 5) يوقف تماماً
  // =========================
  stopMovement();

  delay(1000);


  // =========================
  // 6) هاي فايف يسار
  // =========================
  highFiveLeft();


  // يبقى ثابت بعد النهاية
  stopMovement();

  while (true) {
  }
}



// =================================
// الرقص
// القدام عكس الخلف
// نفس المدى 85 - 95
// =================================
void dance(unsigned long duration) {

  unsigned long startTime = millis();

  while (millis() - startTime < duration) {

    // =========================
    // القدام 85 -> 95
    // الخلف 95 -> 85
    // =========================
    for (int pos = MIN_ANGLE; pos <= MAX_ANGLE; pos++) {

      int rearPos = MAX_ANGLE - (pos - MIN_ANGLE);

      frontLeft.write(pos);

      // تعويض ارتفاع اليد اليمين
      frontRight.write(pos + FR_OFFSET);

      rearRight.write(rearPos);
      rearLeft.write(rearPos);

      // نحفظ آخر وضع
      lastFront = pos;
      lastRear = rearPos;

      delay(25);

      if (millis() - startTime >= duration) {
        break;
      }
    }


    // =========================
    // القدام 95 -> 85
    // الخلف 85 -> 95
    // =========================
    for (int pos = MAX_ANGLE; pos >= MIN_ANGLE; pos--) {

      int rearPos = MAX_ANGLE - (pos - MIN_ANGLE);

      frontLeft.write(pos);
      frontRight.write(pos + FR_OFFSET);

      rearRight.write(rearPos);
      rearLeft.write(rearPos);

      lastFront = pos;
      lastRear = rearPos;

      delay(25);

      if (millis() - startTime >= duration) {
        break;
      }
    }
  }
}



// =================================
// توقف الحركة
// ما يرجعهم 90
// يثبتهم في آخر مكان وصلوا له
// =================================
void stopMovement() {

  frontLeft.write(lastFront);

  frontRight.write(lastFront + FR_OFFSET);

  rearRight.write(lastRear);
  rearLeft.write(lastRear);
}



// =================================
// هاي فايف يمين
// =================================
void highFiveRight() {

  int startAngle = lastFront + FR_OFFSET;

  // ترتفع
  for (int pos = startAngle;
       pos <= RIGHT_HIGH_FIVE;
       pos++) {

    frontRight.write(pos);
    delay(15);
  }

  // تثبت فوق
  delay(800);

  // تنزل
  for (int pos = RIGHT_HIGH_FIVE;
       pos >= startAngle;
       pos--) {

    frontRight.write(pos);
    delay(15);
  }

  // تثبيت باقي الجسم
  stopMovement();

  delay(500);
}



// =================================
// هاي فايف يسار
// الاتجاه معكوس
// =================================
void highFiveLeft() {

  int startAngle = lastFront;

  // ترتفع
  for (int pos = startAngle;
       pos >= LEFT_HIGH_FIVE;
       pos--) {

    frontLeft.write(pos);
    delay(15);
  }

  // تثبت فوق
  delay(800);

  // تنزل
  for (int pos = LEFT_HIGH_FIVE;
       pos <= startAngle;
       pos++) {

    frontLeft.write(pos);
    delay(15);
  }

  stopMovement();

  delay(500);
}