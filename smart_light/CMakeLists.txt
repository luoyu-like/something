cmake_minimum_required(VERSION 3.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(smart_light)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_degault_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
    "action/GradualBrightness.action"
    DEPENDENCIES buildtin_interfaces)

add_executable(light_sensor_pubisher src/light_sersor_publisher.cpp)
ament_target_dependencies(light_sensor_pubisher rclcpp std_msgs)
add_executable(light_switch_server src/light_switch_server.cpp)
ament_target_dependencies(light_switch_server rclcpp std_srvs)
add_executable(light_switch_client src/light_switch_client.cpp)
ament_target_dependencies(light_switch_client rclcpp std_srvs)
add_executable(light_action_server src/light_action_server.cpp)
ament_target_dependencies(light_action_server rclcpp rclcpp_action)
add_executable(light_action_client src/light_action_client.cpp)
ament_target_dependencies(light_action_client rclcpp rclcpp_action)
install(TARGET
  light_sensor_pubisher
  light_switch_server
  light_switch_client
  light_action_server
  light_action_client
  DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(rosidl_default_runtime)
ament_package()
