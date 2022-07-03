#pragma once

#include <frc/Joystick.h>

/**
 * @brief Controller class
 * We bind the raw axis of the joystick to something user friendly/readable
 * 
 */
class Controller {
 public:
  
  double getLeftY() {
    return _joystick.GetRawAxis(2); // raw axis 2 should be the left Y axis for logitech gamepad
  }

  double getRightY() {
    return _joystick.GetRawAxis(5); // raw axis 5 should be right Y
  }

  bool buttonX() {
    return _joystick.GetRawButton(1);
  }

  bool buttonA() {
    return _joystick.GetRawButton(2);
  }

  bool buttonB() {
    return _joystick.GetRawButton(3);
  }

  bool buttonY() {
    return _joystick.GetRawButton(4);
  }

 private:
  frc::Joystick _joystick{0};
};