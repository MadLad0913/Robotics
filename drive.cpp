#include "main.h"

//FUNCTION PROTOTYPES
void setDrive(int left, int right) {
  driveLeftFront = left;
  driveLeftBack = left;
  driveRightFront = -right;
  driveRightBack = -right;
}

void resetDriveEncoders() {
  driveLeftFront.tare_position();
  driveLeftBack.tare_position();
  driveRightFront.tare_position();
  driveRightBack.tare_position();
}

double avgDriveEncoderValue() {
  return (fabs(driveLeftFront.get_position()) +
         fabs(driveLeftBack.get_position()) +
         fabs(driveRightFront.get_position()) +
         fabs(driveRightBack.get_position())) / 4;
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotors() {
  int leftJoystickY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int rightJoystickY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  if(abs(leftJoystickY) < 10)
    leftJoystickY = 0;
  if(abs(rightJoystickY) < 10)
    rightJoystickY = 0;
  setDrive(leftJoystickY, rightJoystickY);
}

//AUTONOMOUS
void translate(int units, int voltage) {
  //define a direction based on units provided
  int direction = abs(units) / units; //either 1 or -1
  //reset motor encoders
  resetDriveEncoders();
  //drive forward until all units are reached
  while(avgDriveEncoderValue() < abs(units)) {
    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }
  //brief brake
  setDrive(-10, 10);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}
