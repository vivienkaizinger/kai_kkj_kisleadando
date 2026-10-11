
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="ros2_parking_radar",
            executable="distance_sensor",
            name="distance_sensor",
            output="screen"
        ),
        Node(
            package="ros2_parking_radar",
            executable="parking_monitor",
            name="parking_monitor",
            output="screen"
        )
    ])
