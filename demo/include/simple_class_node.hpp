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

class SimpleClassNode {
 public:
    SimpleClassNode(const ros::NodeHandle &node_handle,
            const ros::NodeHandle &private_node_handle);
    ~SimpleClassNode() = default;
    void init();
    
 private:
 
};


#endif  // DEMO_SIMPLE_CLASS_NODE_HPP
