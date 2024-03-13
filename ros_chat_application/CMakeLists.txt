cmake_minimum_required(VERSION 2.8.3)
project(ros_chat_application)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(sender src/sender.cpp)
target_link_libraries(sender ${catkin_LIBRARIES})

add_executable(receiver src/receiver.cpp)
target_link_libraries(receiver ${catkin_LIBRARIES})
