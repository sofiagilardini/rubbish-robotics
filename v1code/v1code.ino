// create motor structs with attributes
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

  dc(int pP, int e1P, int e2P) {
    powerPort = pP;
    enc1Pin = e1P;
    enc2Pin = e2P;
    Encoder enc(enc1Pin, enc2Pin);
  }
};

struct stepper {
  int dirPin;
  int stepPin;
};

void setup() {
  // Define input variables here
  
  // create motors
  struct dc motor1;
  struct dc motor2;

  motor1.powerPort = 1;
  motor1.enc1Pin = 2;
  motor1.enc2Pin = 3;
  motor1.enc = Encoder(motor1.enc1Pin, motor1.enc2Pin = 3);

  motor2.powerPort = 1;
  motor2.enc1Pin = 2;
  motor2.enc2Pin = 3;

  AF_DCMotor m1(motor1.powerPort);
  AF_DCMotor m2(motor2.powerPort);


  // enter all the dimensions
}

// void moveNStepsDC(struct dc motor, int nSteps, int dir, int speed) {
//   motor.setSpeed(speed);
//   motor.run(dir);
//   initPos = motor.enc.read()
//   desiredStepDelta = 
//   while (motor.enc.read() - initPos != (2*dir - 1)*nSteps) {  }
//   motor.run(release);
//   motor.enc.write(0);
// }

void moveNStepsDC(AF_DCMotor motor, int nSteps, int dir, int speed);

moveNStepsDC(motor, nSteps, dir, speed) {
  motor.setSpeed(speed);
  motor.run(dir);
  while (abs(motor.enc.read()) < nSteps) {  }
  motor.run(release);
  motor.enc.write(0);
}


void loop() {
  moveNStepsDC(m1, 2000, FORWARD, 200);

}
