/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: multi_threads_node_instance.cpp
 *   Created on: 10, 03, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "simple_class_node.hpp"

int main(int argc, char** argv) {
    std::string node_name = "simple_class_node";
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh("");
    ros::NodeHandle nh_private("~");
    demo::SimpleClassNode node(nh, nh_private);
    ROS_INFO("Initialized a multi-thread node.");
    ros::MultiThreadedSpinner s(4); // Use 2 threads
    
    ROS_INFO_STREAM("Main loop in thread:" << boost::this_thread::get_id());
    ros::spin(s);
}