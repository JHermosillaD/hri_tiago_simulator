cmake_minimum_required(VERSION 3.0.2)
project(sim_world)

find_package(catkin REQUIRED)

## System dependencies are found with CMake's conventions
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  move_base_msgs
  actionlib
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sim_world
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(navigation_goals src/main.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(navigation_goals
  ${catkin_LIBRARIES}
)
