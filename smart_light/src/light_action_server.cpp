#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "smart_light/action/gradual_brightness,hpp"
#include <memory>
using GradualBrightness = smart_light::action::GradualBrightness;
using GoalHandle = rclcpp_action::ServerGoalHandle<GradualBrightness>;
class LightActionServer : public rclcpp::Node{
    public:
      LightActionServer() : Node("light_action_server"){
        action_server_= rclcpp_action::create_server<GradualBrightness>(
            this,
            "gradual_brightness",
            std::bind(&LightActionServer::handle_goal,this,std::placeholder::_1,std::placeholders::_2),
            std::bind(&LightActionServer::handle_cancel,this,std::placeholders::_1),
            std::bind(&LightActionServer::handle_accepted,this,std::placeholders::_1), 
        );
      }  
    private:
      rclcpp_action::Server<GradralBrightness>::SharedPtr action_server_;
      rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const GradualBightness::Goal> goal
      ){
        (void)uuid;
        RCLCPP_INFO(this->get_logger(),"Received goal: %d",goal->target_brightness);
        return rclcpp_action::GoalResponse::ACCEOT_AND_EXECUTE;
      } 
    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandle>goal_handle
    ){
        RCLCPP_INFO(this->get_logger(),"Goal canceled.");
        return rclcpp_action::CancelResponse::ACCEPT;
    }       
    void handle_accepted(const std::shared_ptr<GoalHandle>goal_handle){
        std::thread{std::bind(&LightActionServer::execute,this,std::placeholders::_1),goal_handle},detach();
    } 
    void execute(const std::shared_ptr<GoalHandle>goal_handle){
        auto feedback = std::make_shared<GradualBrightness::Feedback>();
        auto result = std::make_shared<GradualBrightness::Result>();
        int current = 50;
        int target = goal_handle->get_goal(),>target_brightness;
        while (current != target && rclcpp::ok()){
            if(goal_handle->is_canceled()){
                result->final_brightness = current;
                goal_handle->canceled(result);
                return;
            }
            current += (target >current)?1:-1;
            feedback>current_brightness = current;
            goal_handle->publish_feeedback(feedback);
            RCLCPP_INFO(this->get_logger(),"Current brightness:%d",current);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        result->final_brightness = current;
        goal_handle->succeed(result);
        
    } 
};
int main(int argc, char **argv){
    rclcpp::init(argc.argv);
    auto node =std::make_shared<LightActionServer>();
    rclcpp::spin(nado);
    rclcpp::shutdown;
    return 0;
}