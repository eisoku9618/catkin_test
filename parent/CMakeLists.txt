cmake_minimum_required(VERSION 2.8.3)
project(parent)

find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hoge_library
  )

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  )

add_library(hoge_library
  src/hoge.cpp
  )

message(STATUS "catkin_INCLUDE_DIRS of parent package: ${catkin_INCLUDE_DIRS}")
message(STATUS "catkin_LIBRARIES of parent package: ${catkin_LIBRARIES}")
