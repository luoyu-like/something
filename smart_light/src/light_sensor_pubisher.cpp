#include"rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int8.hpp"
int main(int argc,char **argv){
    rclcpp::init(argc,argv);
    auto node = rclcpp::Node::make_shared("light_sensor");
    auto publisher = node->create_pubisher<std_msgs::msg::Int8>("light_brightness",10);
    auto  massage =std_msgs::msg::Int8();
    message.data = 50;
    rclcpp::Rate loop_rate(1);
    while (rclcpp::ok() ){
        message.data = (massage.data + 5) % 101;
        publisher->publish(massage);
        RCLCPP_INFO(node->get_logger(),"Pubilshed brightness:%d",message.data);
        rclcpp::spin_some(node);
        loop_rate.sleep();

    }
    rclcpp::shutdown();
    return 0;
}