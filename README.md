# Spatial HRI simulator
![Static Badge](https://img.shields.io/badge/ros%20-%20noetic%20-blue) ![GitHub repo size](https://img.shields.io/github/repo-size/jhermosillad/hri_tiago_simulator)
 ![GitHub top language](https://img.shields.io/github/languages/top/jhermosillad/hri_tiago_simulator) 

ROS package for the simulation of different gazebo-based scenarios using a TIAGo mobile robot and moving actors for human-robot interaction research.

> [!WARNING]  
> Work in progress

## Set-up
### Requirements
- [x] ROS noetic
- [x] Adequate workspace for [TIAGo's simulation](http://wiki.ros.org/Robots/TIAGo/Tutorials/Installation/InstallUbuntuAndROS)
      
### Installation
Clone the repository to TIAGo workspace source path.
```
user@hostname:~/tiago_public_ws/src$ git clone https://github.com/JHermosillaD/hri_tiago_simulator.git
```
Build the workspace using catkin build tool.
```
user@hostname:~/tiago_public_ws$ catkin build -DCATKIN_ENABLE_TESTING=0 -j $(expr `nproc` / 2)
```
## Usage

Select the scenario and execute the launcher.
```
user@hostname:~/tiago_public_ws$ roslaunch hri_tiago_simulator scenario_1.launch
```
## Visualization
Tiago's aviable topics can be shown in rviz

<img width="702" height="382" src="/media/demo.gif">
