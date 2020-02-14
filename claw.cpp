#include "main.h"

//FUNCTION PROTOTYPES
void setClaw(int power) {
  claw = power;
}

//DRIVER CONTROL FUNCTIONS
void setClawMotor() {
  int clawPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
  setClaw(clawPower);
}
