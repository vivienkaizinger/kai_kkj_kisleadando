# `kai_kkj_kisleadando` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/vivienkaizinger/kai_kkj_kisleadando
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select kai_kkj_kisleadando --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch kai_kkj_kisleadando launch_example1.launch.py
```

## Graph

```mermaid
flowchart LR
    A(["/distance_sensor"]) --> B["/distance<br/>std_msgs/Float32"]
    B --> C(["/parking_monitor"])
    C --> D["/parking_status<br/>std_msgs/String"]

    style A fill:#F44336,stroke:#222,color:#fff
    style B fill:#35AFC4,stroke:#222,color:#000
    style C fill:#F44336,stroke:#222,color:#fff
    style D fill:#35AFC4,stroke:#222,color:#000
```
