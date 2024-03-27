#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "motor_driver_wrapper/motor_driver_node.hpp"

MotorDriverNode::MotorDriverNode(int max_speed) : Node("motor_driver_node")
{
  motor_ = std::make_unique<MotorDriver>(max_speed);
}
void MotorDriverNode::stop()
{
  motor_->stop();
}

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto motor_driver_node = std::make_shared<MotorDriverNode>(100);
  rclcpp::spin(motor_driver_node);
  motor_driver_node->stop();
  rclcpp::shutdown();
}
