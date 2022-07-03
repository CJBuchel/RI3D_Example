#pragma once

#include <rev/CANSparkMax.h> // CAN spark max. there is also PWM

class Drivetrain {
 public:

  /**
   * @brief Set the drivetrain (left power, right power)
   * 
   * @param left 
   * @param right 
   */
  void set(double leftPower, double rightPower) {
    _topLeft.Set(leftPower);
    _bottomLeft.Set(leftPower);

    _topRight.Set(rightPower);
    _bottomRight.Set(rightPower);
  }

 private:
  rev::CANSparkMax _topLeft{0, rev::CANSparkMaxLowLevel::MotorType::kBrushed};
  rev::CANSparkMax _topRight{1, rev::CANSparkMaxLowLevel::MotorType::kBrushed};

  rev::CANSparkMax _bottomLeft{2, rev::CANSparkMaxLowLevel::MotorType::kBrushed};
  rev::CANSparkMax _bottomRight{3, rev::CANSparkMaxLowLevel::MotorType::kBrushed};
};