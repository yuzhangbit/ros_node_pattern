/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: single_thread_node_instance.cpp
 *   Created on: 10, 03, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "simple_node_class.hpp"
#include <string>

int main(int argc, char** argv) {
    std::string node_name = "simple_class_node";
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh("");
    ros::NodeHandle nh_private("~");
    demo::SimpleNodeClass node(nh, nh_private);
    ROS_INFO("Initialized single-thread class node.");
    ROS_INFO_STREAM("Main loop in thread:" << boost::this_thread::get_id());
    ros::spin();
}
