#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// =====================
// Ultrasonic Sensor
// =====================
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

// =====================
// Motor & Motion Settings
// =====================
#define CRUISE_SPEED 150
#define TURN_SPEED   170   
#define BACK_SPEED   140
#define ACC_STEP     3
#define SAFE_DISTANCE 18

// =====================

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

// Motor order (IMPORTANT)
AF_DCMotor motor1(1, MOTOR12_1KHZ); // Front Left
AF_DCMotor motor2(2, MOTOR12_1KHZ); // Front Right
AF_DCMotor motor3(3, MOTOR34_1KHZ); // Back Left
AF_DCMotor motor4(4, MOTOR34_1KHZ); // Back Right

bool goesForward = false;
int distance = 100;

// =====================
// SETUP
// =====================
void setup() {
  myservo.attach(10);
  myservo.write(115);     // Center
  delay(1500);
  distance = readPing();
}

// =====================
// LOOP
// =====================
void loop() {

  if (distance <= SAFE_DISTANCE) {

    moveStop();
    delay(150);

    moveBackward();
    delay(350);
    moveStop();
    delay(150);

    int rightDist = lookRight();
    delay(150);
    int leftDist  = lookLeft();
    delay(150);

    if (rightDist > leftDist)
      pivotRight();
    else
      pivotLeft();
  }
  else {
    moveForward();
  }

  distance = readPing();
}

// =====================
// SENSOR FUNCTIONS
// =====================
int readPing() {
  delay(60);
  int cm = sonar.ping_cm();
  return (cm == 0) ? MAX_DISTANCE : cm;
}

int lookRight() {
  myservo.write(45);
  delay(350);
  int d = readPing();
  myservo.write(115);
  return d;
}

int lookLeft() {
  myservo.write(175);
  delay(350);
  int d = readPing();
  myservo.write(115);
  return d;
}

// =====================
// MOTOR CONTROL
// =====================
void setSpeed(int m1, int m2, int m3, int m4) {
  motor1.setSpeed(m1);
  motor2.setSpeed(m2);
  motor3.setSpeed(m3);
  motor4.setSpeed(m4);
}

void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  goesForward = false;
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

    for (int s = 0; s <= CRUISE_SPEED; s += ACC_STEP) {
      setSpeed(s, s, s, s);
      delay(5);
    }
  }
}

void moveBackward() {
  goesForward = false;

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  setSpeed(BACK_SPEED, BACK_SPEED, BACK_SPEED, BACK_SPEED);
}

// =====================
// PIVOT TURN (KEY PART)
// =====================

void pivotRight() {
  // Left side moves
  motor1.run(FORWARD);   // Front Left
  motor3.run(FORWARD);   // Back Left

  // Right side stops
  motor2.run(RELEASE);
  motor4.run(RELEASE);

  setSpeed(TURN_SPEED, 0, TURN_SPEED, 0);
  delay(700);
  moveStop();
}

void pivotLeft() {
  // Right side moves
  motor2.run(FORWARD);   // Front Right
  motor4.run(FORWARD);   // Back Right

  // Left side stops
  motor1.run(RELEASE);
  motor3.run(RELEASE);

  setSpeed(0, TURN_SPEED, 0, TURN_SPEED);
  delay(700);
  moveStop();
}