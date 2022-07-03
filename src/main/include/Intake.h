#pragma once

#include <frc/motorcontrol/Victor.h>

class Intake {
 public:

 /**
  * @brief Set the power of the intake
  * 
  * @param power 
  */
  void set(double power) {

  }

 private:
  frc::Victor _intake{0}; // pwm motor controller on DIO pin 0
};