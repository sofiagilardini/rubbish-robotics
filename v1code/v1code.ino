// create motor structs with attributes

struct dc {
  int powerPort;
  int enc1Pin;
  int enc2Pin;
}

struct stepper {
  int dirPin;
  int stepPin;
}

void setup() {
  // Define input variables here
  #include <AFMotor.h>

  // Macros
  #define CW 0
  #define CCW 1
  
  // create motors
  struct dc motor1;
  struct dc motor2;

  motor1.powerPort = 1;
  motor1.enc1Pin = 2;
  motor1.enc2Pin = 3;

  motor2.powerPort = 1;
  motor2.enc1Pin = 2;
  motor2.enc2Pin = 3;

  AF_DCMotor m1(motor1.powerPort);
  AF_DCMotor m2(motor2.powerPort);

  // enter all the dimensions
}

void moveNStepsDC(struct dc motor, int nSteps, int dir, int speed) {
  int stepsCompleted = 0;
  motor.setSpeed(speed);
  while (stepsCompleted < nSteps) {
    motor.run(dir);
    
  }
  motor.run(release);
}


void loop() {
  // put your main code here, to run repeatedly:

}
