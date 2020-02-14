#include "main.h"

//OPERATOR CONTROL
void opcontrol() {
  while (true) {
		//CLAW
    setClawMotor();
		//DRIVE
    setDriveMotors();
    setDriveMotorH();
		//LIFT
    setLiftMotors();
		pros::delay(10);
  }
}
