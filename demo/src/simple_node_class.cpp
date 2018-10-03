/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: simple_class_node.cpp
 *   Created on: 10, 02, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <string>
#include "simple_node_class.hpp"


namespace demo {
SimpleNodeClass::SimpleNodeClass(const ros::NodeHandle &node_handle,
                                 const ros::NodeHandle &private_node_handle)
    :nh_(node_handle),
     pnh_(private_node_handle),
     pub_periodic_count_(0),
     sub1_callback_count_(0),
     sub2_callback_count_(0),
     sub3_callback_count_(0) {
    this->init();
}

void SimpleNodeClass::init() {
    periodic_pub_ = pnh_.advertise<std_msgs::String>("/publisher", 1);
    sub1_ = pnh_.subscribe("/subscriber",
                          1,
                          &SimpleNodeClass::subscriberCallback1,
                          this);
    sub2_ = pnh_.subscribe("/subscriber",
                           1,
                           &SimpleNodeClass::subscriberCallback2,
                           this);
    sub3_ = pnh_.subscribe("/subscriber",
                           1,
                           &SimpleNodeClass::subscriberCallback3,
                           this);
    periodic_timer_ = pnh_.createTimer(ros::Duration(0.1),
                                       &SimpleNodeClass::periodicTimerCallback,
                                       this);
    
}

void SimpleNodeClass::periodicTimerCallback(const ros::TimerEvent &event) {
    std_msgs::String msg;
    
    std::stringstream ss;
    ss << "Periodic Publisher " << pub_periodic_count_;
    msg.data = ss.str();
    
    ROS_INFO_STREAM(" " << msg.data.c_str() << ", in thread:"
                        << boost::this_thread::get_id());
    
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    periodic_pub_.publish(msg);
    pub_periodic_count_++;
}

void SimpleNodeClass::subscriberCallback1(
        const std_msgs::String::ConstPtr &msg) {
    ROS_INFO_STREAM("First subscriber callback "
                            << sub1_callback_count_ << ", in thread:"
                            << boost::this_thread::get_id());
    sub1_callback_count_++;
    ros::Rate loop_rate(5);
    // sleep for 200ms
    loop_rate.sleep();
}

void SimpleNodeClass::subscriberCallback2(
        const std_msgs::String::ConstPtr &msg) {
    ROS_INFO_STREAM("Second subscriber callback "
                            << sub2_callback_count_ << ", in thread:"
                            << boost::this_thread::get_id());
    sub2_callback_count_++;
    ros::Rate loop_rate(5);
    // sleep for 200ms
    loop_rate.sleep();
}
void SimpleNodeClass::subscriberCallback3(
        const std_msgs::String::ConstPtr &msg) {
    ROS_INFO_STREAM("Third subscriber callback "
                            << sub3_callback_count_ << ", in thread:"
                            << boost::this_thread::get_id());
    sub3_callback_count_++;
    ros::Rate loop_rate(5);
    // sleep for 200ms
    loop_rate.sleep();
}
}  // namespace demo


