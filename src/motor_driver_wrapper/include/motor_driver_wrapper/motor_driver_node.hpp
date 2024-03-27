#include "rclcpp/rclcpp.hpp"

#include "motor_driver_wrapper/motor_driver.hpp"

class MotorDriverNode : public rclcpp::Node
{
public:
  MotorDriverNode(int max_speed);
  void stop();

private:
  std::unique_ptr<MotorDriver> motor_;
};
