
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"

class ParkingMonitor : public rclcpp::Node
{
public:
  ParkingMonitor() : Node("parking_monitor")
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>(
      "/parking_status", 10);

    subscription_ = this->create_subscription<std_msgs::msg::Float32>(
      "/distance",
      10,
      std::bind(
        &ParkingMonitor::check_distance,
        this,
        std::placeholders::_1));
  }

private:
  void check_distance(
    const std_msgs::msg::Float32::SharedPtr message)
  {
    float distance = message->data;
    std_msgs::msg::String status;

    if (distance < 0.5f) {
      status.data = "STOP";
    } else if (distance <= 2.0f) {
      status.data = "WARNING";
    } else {
      status.data = "SAFE";
    }

    publisher_->publish(status);

    RCLCPP_INFO(
      this->get_logger(),
      "Distance: %.2f m | Status: %s",
      distance,
      status.data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParkingMonitor>());
  rclcpp::shutdown();
  return 0;
}
