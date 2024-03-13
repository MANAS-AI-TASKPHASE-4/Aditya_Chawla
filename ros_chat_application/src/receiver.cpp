#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: [%s]", msg->data.c_str());

    // Generate a response message
    std_msgs::String response_msg;
    response_msg.data = "Hello! I am the chatbot. " + msg->data;

    // Publish the response message to the chat topic
    ROS_INFO("Publishing response: [%s]", response_msg.data.c_str());
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("chat", 1000);
    pub.publish(response_msg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "chatbot");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chat", 1000, chatterCallback);

    ROS_INFO("Chatbot node started.");

    // Instead of ros::spin(), use a loop with ros::spinOnce() to handle callbacks
    ros::Rate loop_rate(10);  // Adjust loop rate if needed
    while (ros::ok()) {
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
