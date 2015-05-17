cmake_minimum_required(VERSION 2.8.3)

project(anglesender)

ADD_DEFINITIONS(-std=c++0x)


## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	std_msgs 
	genmsg 
	message_generation 
)




## Declare a catkin package
catkin_package(
#	INCLUDE_DIRS include
	LIBRARIES controls
	CATKIN_DEPENDS roscpp std_msgs  
	)
	


## Build talker and listener
include_directories(
    include
	${catkin_INCLUDE_DIRS}
	${roscpp_INCLUDE_DIRS}
	${rospy_INCLUDE_DIRS}
)



add_executable(anglesend anglepublish.cpp)
target_link_libraries(anglesend ${catkin_LIBRARIES})
add_dependencies(anglesend roscpp std_msgs)



