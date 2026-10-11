
cmake_minimum_required(VERSION 3.8)
project(ros2_parking_radar)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(distance_sensor src/distance_sensor.cpp)
ament_target_dependencies(distance_sensor rclcpp std_msgs)

add_executable(parking_monitor src/parking_monitor.cpp)
ament_target_dependencies(parking_monitor rclcpp std_msgs)

install(TARGETS
  distance_sensor
  parking_monitor
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
