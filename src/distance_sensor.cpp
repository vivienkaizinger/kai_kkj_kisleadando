
#include <chrono>
#include <functional>
#include <memory>
#include <random>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class DistanceSensor : public rclcpp::Node
{
public:
  DistanceSensor()
  : Node("distance_sensor"),
    generator_(std::random_device{}()),
    distribution_(0.2f, 5.0f)
  {
    publisher_ = this->create_publisher<std_msgs::msg::Float32>(
      "/distance", 10);

    timer_ = this->create_wall_timer(
      1s, std::bind(&DistanceSensor::publish_distance, this));
  }

private:
  void publish_distance()
  {
    std_msgs::msg::Float32 message;
    message.data = distribution_(generator_);

    publisher_->publish(message);

    RCLCPP_INFO(
      this->get_logger(),
      "Distance: %.2f m",
      message.data);
  }

  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

  std::mt19937 generator_;
  std::uniform_real_distribution<float> distribution_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DistanceSensor>());
  rclcpp::shutdown();
  return 0;
}
