/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>


Servo frontRight;
Servo frontLeft;
Servo rearRight;
Servo rearLeft;
int pos = 0;
// Servo pins
const int FR_PIN = 11;
const int FL_PIN = 10;
const int RR_PIN = 9;
const int RL_PIN = 8;

void setup() {
  frontRight.attach(FR_PIN); 
  frontLeft.attach(FL_PIN);
  rearRight.attach(RR_PIN);
  rearLeft.attach(RL_PIN);
   // attaches the serv on pin 9 to the Servo object
}


void loop() {

  // Front: 80 -> 100
  // Rear:  100 -> 80
  for (pos = 80; pos <= 100; pos++) {

    frontRight.write(pos);
    frontLeft.write(pos);

    rearRight.write(180 - pos);
    rearLeft.write(180 - pos);

    delay(15);
  }

  // Front: 100 -> 80
  // Rear:   80 -> 100
  for (pos = 100; pos >= 80; pos--) {

    frontRight.write(pos);
    frontLeft.write(pos);

    rearRight.write(180 - pos);
    rearLeft.write(180 - pos);

    delay(15);
  }
}