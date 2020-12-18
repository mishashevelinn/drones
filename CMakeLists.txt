cmake_minimum_required(VERSION 3.17)
project(drones)

set(CMAKE_CXX_STANDARD 98)

add_executable(drones main.cpp Drone.cpp Drone.h Vector.cpp Vector.h Wood.cpp Wood.h DroneList.cpp DroneList.h Node.cpp Node.h Square.cpp Square.h Parser.cpp Parser.h)