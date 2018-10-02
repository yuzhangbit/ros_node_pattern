/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: simple_class_node.hpp
 *   Created on: 10, 02, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#ifndef DEMO_SIMPLE_CLASS_NODE_HPP
#define DEMO_SIMPLE_CLASS_NODE_HPP

#include <ros/ros.h>
#include <std_msgs/String.h>
namespace demo {

class SimpleClassNode {
 public:
    SimpleClassNode(const ros::NodeHandle &node_handle,
            const ros::NodeHandle &private_node_handle);
    ~SimpleClassNode() = default;
    void init();
    void subscriberCallback(const std_msgs::String::ConstPtr& msg);
    void periodicTimerCallback(const ros::TimerEvent& event);
 private:
    // public ros node handle
    ros::NodeHandle nh_;
    // private ros node handle
    ros::NodeHandle pnh_;
    std::string node_name_{"simple class node"};
    // timer
    ros::Timer periodic_timer_;
    
    // subscriber and publisher
    ros::Subscriber sub_;
    // publisher
    ros::Publisher periodic_pub_;
    
    unsigned int sub_callback_count_;
    unsigned int pub_periodic_count_;
}; // class SimpleClassNode

}  // namespace demo

#endif  // DEMO_SIMPLE_CLASS_NODE_HPP
