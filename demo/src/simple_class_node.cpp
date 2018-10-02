/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: simple_class_node.cpp
 *   Created on: 10, 02, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */




// The Node Instance

int main(int argc, char** argv) {
    std::string node_name = "simple_class_node";
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh("");
    ros::NodeHandle nh_private("~");
    ompl_ros::OmplPlanner astar(nh, nh_private, node_name);
    ROS_INFO("Initialized ompl planner node.");
    ros::spin();
}