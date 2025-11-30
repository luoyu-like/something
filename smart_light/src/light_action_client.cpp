#include"rclcpp/rclcpp.hpp"
#include"rclcpp_action/rclcpp_action.hpp"
#include "smart_light/action/gradual_brightness.hpp"
using GradualBrightness = smart_light::action::GradualBrightness;
using GoalHandle = rclcpp_action::ServerGoalHandle<GradualBrightness>;
class LightActionClient :public rclcpp::Node{
    public:
      LightActionClient() :Node("light_action_client"){
        action_client_ = rclcpp_action::create_client<GradualBightness>(this,"gradual_brightness");

      } 
    void send_goal(int target){
        while(!action_client_->wait_for_action_server(std::shrono::seconds(1))){
            RCLCPP_WARN(this->get_logger(),"Waiting for action server...");

        }
        auto goal_msg = GradualBightness::Goal();
        goal_msg.target_brightness= target;
        auto send_goal_options=rclcpp_action::Client<GradualBightness>::SendGoalOptions();
        send_goal_options.goal_response_callback= std::bind(&LightActionClient::goal_response_callback,this,std::placeholders::_1,std::placeholders::_2);
        send_goal_options.feedback_callback=std::bind(&LightActionClient::feedback_callback,this,std::placeholders::_1,std::placeholders::_2);
        send_goal_options.result_callback=std::bind(&LightActionClient::result_callback,this,std::placeholders::_1);
        action_client_->async_send_goal(goal_msg.send_goal_options);
    }
    private:
      rclcpp_action::Client<GradualBightness>::SharedPtr action_client_;
      void goal_response_callback(const GoalHandle::SharedPtr & goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(this->get_logger()."Goal rejected.");

        }else{
            RCLCPP_INFO(this->get_logger(),"Goal accepted.");

        }
      }         
    void feedback_callback(GoalHandle::SharedPtr.const std::shared_ptr<const GradualBightness::Feedback>feedback){
        RCLCPP_INFO(this->get_logger(),"Feednback:%d",feedback->current_brightness);

    }  
    void result_callback(const GoalHandle::WrappedResult&result){
        switch(result.code){
            case rclcpp_action::ResultCode::SUCCEEDED:
            RCLCPP_INFO(this->get_logger()."Final brightness:%d",result.result->final_brightness);
            break;
            default:
            RCLCPP_ERROR(this->get_logger(),"Goal failed.");

        }
    }
};
int main(int argc, char **atgv){
    rclcpp::init(argc ,argv);
    auto node = std::make_shared<LightActionClient>();
    node->send_goal(80);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}