cmake_minimum_required(VERSION 2.8.3)
project(child)

find_package(catkin REQUIRED parent)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  )

add_executable(main src/main.cpp)
target_link_libraries(main
  ${catkin_LIBRARIES}
  )

message(STATUS "catkin_INCLUDE_DIRS of child package: ${catkin_INCLUDE_DIRS}")
message(STATUS "catkin_LIBRARIES of child package: ${catkin_LIBRARIES}")
