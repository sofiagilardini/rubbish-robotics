#include <AFMotor.h>
#include <Encoder.h>

// Macros
#define CW 0
#define CCW 1

class dc {
public:
  int powerPort;
  int enc1Pin;
  int enc2Pin;
  int position = 0;
  Encoder enc;
  AF_DCMotor motor;

  dc(int pP, int e1P, int e2P, int motorPort) : powerPort(pP), enc1Pin(e1P), enc2Pin(e2P), enc(e1P, e2P), motor(motorPort) {
  }
};

struct stepper {
  int dirPin;
  int stepPin;
};

dc motor1(1, 7, 6, 1); // Declare and initialize motor1 in the global scope
dc motor2(1, 7, 6, 2); // Declare and initialize motor2 in the global scope

void setup() {
  Serial.begin(9600);
  // Define input variables here
}

int moveNStepsDC(dc motor, int nSteps, int dir, int speed, int initpos) {

  long initPos = motor.enc.read();
  int oldSignal = motor.enc.read();
  Serial.println("stop1");
  //motor.motor.setSpeed(speed);
  Serial.println("stop2");

  //motor.motor.run(1);

  Serial.println("stop3");

  motor.motor.setSpeed(speed);
  motor.motor.run(dir);

  motor.position += initpos;

  //while (abs(position - 0) < nSteps) {
  while (abs(motor.position - initpos) < nSteps) {

    //if (motor.enc.read() != oldSignal) {
    if (motor.enc.read() != oldSignal) {
      if (dir == FORWARD)
      motor.position += 1;
      if (dir == BACKWARD)
      motor.position += -1;
      oldSignal = motor.enc.read();
      Serial.println(motor.position);
    }

  }
  
  int finalpos = motor.position;

  return finalpos;


  //motor.motor.run(RELEASE);
  //motor.enc.write(0);
}

// int oldSignal = motor1.enc.read();
// // Serial.println("oldsignal:");
// // Serial.println(oldSignal);
// int position = 0;
long finalpos1 = 0;

void loop() {
  Serial.println("I am starting");
  finalpos1 = moveNStepsDC(motor1, 1000, FORWARD, 500, finalpos1); // Call the function with motor1
  Serial.println("finished first step");
  finalpos1 = moveNStepsDC(motor1, 500, BACKWARD, 500, finalpos1); // Call the function with motor1]

  //motor1.motor.run(RELEASE);  
  // moveNStepsDC(motor1, 2000, FORWARD, 5000); // Call the function with motor1]
  // Serial.println("finished2");
  // delay(1000);  
  // motor1.motor.run(RELEASE);  
  // motor1.motor.setSpeed(2000);
  // motor1.motor.run(1);
  //motor1.motor.run(RELEASE);  

  // //Serial.print("HERE");
  //   //Serial.println(motor1.enc.read());
  //   if (motor1.enc.read() != oldSignal) {
  //   position += 1;
  //   oldSignal = motor1.enc.read();
  //   //Serial.print("position");
  //   Serial.println(position);
    //}

}

int main() {
  setup();
  while (true) {
    loop();
  }
}
