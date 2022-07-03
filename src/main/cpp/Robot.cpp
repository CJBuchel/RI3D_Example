// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

Drivetrain myDrivetrain;
Intake myIntake;
Controller myController;

double deadZone = 0.1; // 10% logitech controllers aren't very good :(

/**
 * @brief Robot boot function
 * When robot powers on, this will run once
 * 
 */
void Robot::RobotInit() {}

/**
 * @brief Robot periodic function
 * Robot will loop this code at all times (will not set motors unless robot is enabled)
 * 
 */
void Robot::RobotPeriodic() {}

/**
 * @brief Runs *once*, when teleop is enabled on driverstation
 * 
 */
void Robot::TeleopInit() {}
/**
 * @brief Loops constantly, when teleop is enabled on driverstation (sequence is after robotInit/teleopInit)
 * 
 */
void Robot::TeleopPeriodic() {
  double leftPower = 0, rightPower = 0;
  double intakePower = 0;

  /**
   * @brief If the absolute value of gamepad left Y, is bigger than 0.1
   * Then set to the y axis value, else set to 0
   * 
   */
  if (std::abs(myController.getLeftY()) > deadZone) {
    leftPower = myController.getLeftY();
  } else {
    leftPower = 0;
  }

  /**
   * @brief If the absolute value of gamepad right Y, is bigger than 0.1
   * Then set to the y axis value, else set to 0
   * 
   */
  if (std::abs(myController.getRightY()) > deadZone) {
    rightPower = myController.getRightY();
  } else {
    rightPower = 0;
  }

  /**
   * @brief if button A is pressed. set intake power to 0.3
   * else, set it to 0
   */
  if (myController.buttonA()) {
    intakePower = 0.3;
  }

  // Set the subsystems
  myDrivetrain.set(leftPower, rightPower);
  myIntake.set(intakePower);
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}


void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}