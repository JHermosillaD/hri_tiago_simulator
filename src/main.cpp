#include <ros/ros.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/String.h>
#include <string>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
using namespace std;

void sendGoal(const move_base_msgs::MoveBaseGoal& goal, int room) {

  MoveBaseClient ac("move_base", true);
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting ...");
  }
  
  ROS_INFO("Sending goal %i", room);
  ac.sendGoal(goal);
  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Success!");
  else
    ROS_INFO("Something went wrong!");
}

void Go_to(int room) {
  move_base_msgs::MoveBaseGoal goal;
  
  if (room == 0){
	goal.target_pose.header.frame_id = "map";
  	goal.target_pose.header.stamp = ros::Time::now();
  	goal.target_pose.pose.position.x = 0.0;
  	goal.target_pose.pose.position.y = 0.0;
	goal.target_pose.pose.orientation.w = 1.0;
  	sendGoal(goal,room);
  }
  else if(room == 1){
	goal.target_pose.header.frame_id = "map";
  	goal.target_pose.header.stamp = ros::Time::now();
  	goal.target_pose.pose.position.x = 8.0;
  	goal.target_pose.pose.position.y = 2.0;
	goal.target_pose.pose.orientation.w = 1.0;
  	sendGoal(goal,room);
  }
  else if(room == 2){
	goal.target_pose.header.frame_id = "map";
  	goal.target_pose.header.stamp = ros::Time::now();
  	goal.target_pose.pose.position.x = -5.0;
  	goal.target_pose.pose.position.y =  0.0;
	goal.target_pose.pose.orientation.w = 1.0;
  	sendGoal(goal,room);
  }
  else if(room == 3){
	goal.target_pose.header.frame_id = "map";
  	goal.target_pose.header.stamp = ros::Time::now();
  	goal.target_pose.pose.position.x = 6.5;
  	goal.target_pose.pose.position.y = 4.5;
	goal.target_pose.pose.orientation.w = 1.0;
  	sendGoal(goal,room);
  }	
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "navigation_goals");
  ros::NodeHandle nh;

  int mystr;
  
  while (ros::ok()) {
    ros::spinOnce();
    cout << "Where? ";
    cin >> mystr;
    Go_to(mystr);
  }
  return 0;
}
