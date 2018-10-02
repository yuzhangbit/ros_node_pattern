/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: simple_class_node.cpp
 *   Created on: 10, 02, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "simple_class_node.hpp"

namespace demo {
SimpleClassNode::SimpleClassNode(const ros::NodeHandle &node_handle,
                                 const ros::NodeHandle &private_node_handle)
    :nh_(node_handle),
     pnh_(private_node_handle),
     pub_periodic_count_(0),
     sub_callback_count_(0){
    this->init();
}

void SimpleClassNode::init() {
    periodic_pub_ = pnh_.advertise<std_msgs::String>("/publisher", 1);
    sub_ = pnh_.subscribe("/subscriber",
                          1,
                          &SimpleClassNode::subscriberCallback,
                          this);
    periodic_timer_ = pnh_.createTimer(ros::Duration(0.1),
                                       &SimpleClassNode::periodicTimerCallback,
                                       this);
    
}

void SimpleClassNode::periodicTimerCallback(const ros::TimerEvent &event) {
    std_msgs::String msg;
    
    std::stringstream ss;
    ss << "Periodic Publisher " << pub_periodic_count_;
    msg.data = ss.str();
    
    ROS_INFO("%s", msg.data.c_str());
    
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    periodic_pub_.publish(msg);
    pub_periodic_count_ ++;
}

void SimpleClassNode::subscriberCallback(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("subscriber callback: [%s], [%d]", msg->data.c_str(), sub_callback_count_);
    sub_callback_count_++;
    ros::Rate loop_rate(2);
    loop_rate.sleep();
}
}  // namespace demo



// The Node Instance

int main(int argc, char** argv) {
    std::string node_name = "simple_class_node";
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh("");
    ros::NodeHandle nh_private("~");
    demo::SimpleClassNode node(nh, nh_private);
    ROS_INFO("Initialized simple class node.");
    ros::spin();
}