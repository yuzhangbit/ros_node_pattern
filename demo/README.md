# demo package

* simple single-thread node: [src/simple_node.cpp](https://github.com/yuzhangbit/ros_node_pattern/blob/master/demo/src/simple_node.cpp), `rosrun demo simple_node`
* single-thread class node: [src/single_thread_node_instance.cpp](https://github.com/yuzhangbit/ros_node_pattern/blob/master/demo/src/single_thread_node_instance.cpp), `rosrun demo single_thread_node_instance`
* multi-thread class node: [src/multi_threads_node_instance.cpp](https://github.com/yuzhangbit/ros_node_pattern/blob/master/demo/src/multi_threads_node_instance.cpp), `rosrun demo multi_thread_node_instance`
* async multi-thread class node: [src/async_multi_threads_node_instance.cpp](https://github.com/yuzhangbit/ros_node_pattern/blob/master/demo/src/async_multi_threads_node_instance.cpp), `rosrun demo async_multi_threads_node_instance`
* A python node publishing messages that trigger callback functions of above nodes: [scripts/sender.py](https://github.com/yuzhangbit/ros_node_pattern/tree/master/demo/scripts), `python sender.py`

See [Several Ways of Writing a ROS Node](https://yuzhangbit.github.io/tools/several-ways-of-writing-a-ros-node/) for details.
