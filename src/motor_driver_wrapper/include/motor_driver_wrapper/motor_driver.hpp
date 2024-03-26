#ifndef MOTOR_DRIVER_HPP
#define MOTOR_DRIVER_HPP

#include <map>
#include <string>

class MotorDriver {
private:
  int max_speed_;
  int current_speed_;
  int voltage_;
  int temperature_;

public:
  // Init communication, set default settings, ...
  MotorDriver(int max_speed = 10);
  // Give a speed that the motor will try to reach
  void setSpeed(int speed);
  // Stop the motor by setting speed to 0
  void stop();
  // Return current speed
  int getSpeed();
  // Return hardware information from the motor
  std::map<std::string, std::string> getStatus();
};
#endif
