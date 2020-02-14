#include "main.h"

//FUNCTION PROTOTYPES
void setDriveTrain(int power) {
  driveTrain = power;
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotorH() {
  int drivePowerH = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) + controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  if(abs(drivePowerH) < 100)
    drivePowerH = 0;
  setDriveTrain(drivePowerH);
}
