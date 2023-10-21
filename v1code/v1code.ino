void setup() {
  // Define input variables here

  // set motor configuration: 0 - DC with encoder, 1 - Stepper
  // #define MOTOR1TYPE 1
  // #define MOTOR2TYPE 0

  // #if MOTOR1TYPE
  //   #define DIRPIN1 2
  //   #define STEPPIN1 3
  //   pinMode(stepPin, OUTPUT);
  //   pinMode(dirPin, OUTPUT);
  // #elif
  //   #ifndef _AF_MOTOR_H
  //     #define _AF_MOTOR_H
  //   #endif
  //   // set power port on motorshield M1 - M4
  //   #define POWPORT 1
  //   // two pins to read encoder output
  //   #define ENC1PIN1 5
  //   #define ENC1PIN2 6
  // #endif

  //  #if MOTOR2TYPE
  //   #define DIRPIN2 2
  //   #define STEPPIN2 3
  //   pinMode(stepPin, OUTPUT);
  //   pinMode(dirPin, OUTPUT);
  // #elif
  //   #ifndef _AF_MOTOR_H
  //     #define _AF_MOTOR_H
  //   #endif
  //   // set power port on motorshield M1 - M4
  //   #define POWPORT 2
  //   // two pins to read encoder output
  //   #define ENC1PIN1 7
  //   #define ENC1PIN2 8
  // #endif

  #include <AFMotor.h>
}

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

// conditional function defintions depending on motor type


void loop() {
  // put your main code here, to run repeatedly:

}
