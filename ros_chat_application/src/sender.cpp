#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "sender");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chat", 1000);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        std::string message;
        std::cout << "Type a message to send: ";
        std::getline(std::cin, message);

        std_msgs::String msg;
        msg.data = message;

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}