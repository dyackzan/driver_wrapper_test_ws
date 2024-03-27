#include "motor_driver_wrapper/motor_driver.hpp"
#include <cstdio>

MotorDriver::MotorDriver(int max_speed)
{
  max_speed_ = max_speed;
  current_speed_ = 0;
  voltage_ = 12;
  temperature_ = 47;
  printf("Motor driver initialized with max_speed: %d\n", max_speed);
}

void MotorDriver::setSpeed(int speed)
{
  if (speed <= max_speed_)
  {
    current_speed_ = speed;
  }
  else
  {
    current_speed_ = max_speed_;
  }
}

void MotorDriver::stop()
{
  current_speed_ = 0;
  printf("Stopping motor driver\n");
}

int MotorDriver::getSpeed()
{
  return current_speed_;
}

std::map<std::string, std::string> MotorDriver::getStatus()
{
  std::map<std::string, std::string> status;
  status["temperature"] = std::to_string(temperature_);
  status["voltage"] = std::to_string(voltage_);

  return status;
}
