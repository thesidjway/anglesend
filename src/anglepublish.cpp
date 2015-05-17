
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <iostream>
#include <string.h>
#include <unistd.h>


int main(int argc, char **argv)
{
  if (argc != 1) {
    ROS_INFO("Please enter one argument.");
  } else {
    ros::init(argc, argv, "anglesender");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("alpha_val_manipulated", 100);

    ros::Rate loop_rate(10);
    int angleread = atoi(*argv);

      std_msgs::Float64 msg;
      msg.data = angleread;
      chatter_pub.publish(msg);
  }
  return 0;
}

