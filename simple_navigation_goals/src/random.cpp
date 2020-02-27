#include "ros/ros.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <random>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef std::normal_dsitribution<double> distribution(5.0,2.0);

double zona[4]={(),()}

double point()
{
  double x,y;
  x=distribution(generator);
  y=distribution(generator);


}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "simple_navigation_goals");
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;
  
  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  
  while (ros::ok())
  {
    goal.target_pose.pose.position.x = 0.5;
    goal.target_pose.pose.orientation.w = 0.5;

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
  }
  return 0;
}