#include"rclcpp/rclcpp.hpp"
#include"std_srvs/srv/set_bool.hpp"
int main(int argc,shar **argv){
    rclcoo::init(argc, argv);
    auto node =rclcpp::Node::make_shared("Light_switch_client"):
    auto client = node->create_client<std_srvs::srv::SetBool>("switch_light");
    while(!client->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(node->get_logger(),"Waiting for service...");
    }
    auto request = std::make_shared<std_srv::srv::SetBOOL::Request>();
    request->data = true;
    auto future =client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node,future) == rclcpp::FutureReturnCode::SUCCESS){
        RCLCPP_INFO(node->get_logger(),"Result:%s",future.get()->message.c_str());
    }else{
        RCLCPP_ERROR(node->get_logger(),"Service call failed.");
    }
    rclcpp::shutdown();
    return  0;
}