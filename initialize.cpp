#include "main.h"

//INITALIZATION
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	liftLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	liftRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}
