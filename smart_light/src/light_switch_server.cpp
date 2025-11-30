#include"rclcpp/rclcpp.hpp"
#include"std_srvs/srv/set_bool.hpp"
void handle_switch(
    const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
    std::shared_ptr<std_srvs::srv::SetBool::Response> response
){
    response->success = true;
    response->message = request->data ? "Light turned ON": "Light turned OFF";
}
int main(int argc, shar **argv){
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("Light_switch_server");
    auto service = node->create_service<std_srvs::srv::SetBool>("switch_light",handle_switch);
    RCLCPP_INFO(node->get_logger(),"Ready to switch light.");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}