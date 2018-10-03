cmake_minimum_required(VERSION 3.0)
project(demo VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)


set(PKG_DEPS
  roscpp
  roslib
  std_msgs)

find_package(catkin REQUIRED COMPONENTS ${PKG_DEPS})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES simple_class_node
  CATKIN_DEPENDS ${PKG_DEPS}
)

add_library(simple_class_node
  src/simple_class_node.cpp)

target_link_libraries(simple_class_node
  ${catkin_LIBRARIES})

add_executable(simple_node
  src/simple_node.cpp)

target_link_libraries(simple_node
  ${catkin_LIBRARIES})

add_executable(single_thread_node_instance
  src/single_thread_node_instance.cpp)

target_link_libraries(single_thread_node_instance
  ${catkin_LIBRARIES}
  simple_class_node)

add_executable(multi_thread_node_instance
  src/multi_thread_node_instance.cpp)
target_link_libraries(multi_thread_node_instance
  ${catkin_LIBRARIES}
  simple_class_node)

add_executable(async_multi_thread_node_instance
  src/async_multi_thread_node_instance.cpp)
target_link_libraries(async_multi_thread_node_instance
  ${catkin_LIBRARIES}
  simple_class_node)







