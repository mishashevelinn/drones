cmake_minimum_required(VERSION 3.17)
project(drones)

set(CMAKE_CXX_STANDARD 98)
set(GCC_COVERAGE_COMPILE_FLAGS "−Wall −ansi −Wpedantic −Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(drones main.cpp Drone.cpp Drone.h Vector.cpp Vector.h Wood.cpp Wood.h DroneList.cpp DroneList.h Node.cpp Node.h Square.cpp Square.h Parser.cpp Parser.h BST.h tree.cpp tree.h cmake-build-debug/BST.cpp cmake-build-debug/BST.h)