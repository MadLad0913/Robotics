#include "main.h"
//FUNCTION PROTOTYPES
void setLift(int power) {
  liftLeft = power;
  liftRight = power;
}

//DRIVER CONTROL FUNCTIONS
void setLiftMotors() {
  int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
  setLift(liftPower);
}
