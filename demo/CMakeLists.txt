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
  CATKIN_DEPENDS ${PKG_DEPS}
)

add_executable(simple_node
  src/simple_node.cpp)

target_link_libraries(simple_node
  ${catkin_LIBRARIES})

add_executable(simple_class_node
  src/simple_class_node.cpp)

target_link_libraries(simple_class_node
  ${catkin_LIBRARIES})





