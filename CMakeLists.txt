cmake_minimum_required(VERSION 3.17)
project(drones)

set(CMAKE_CXX_STANDARD 98)


add_executable(drones main.cpp  BST.h Drone.cpp Drone.h Vector.cpp Vector.h Wood.cpp Wood.h Square.cpp Square.h Parser.cpp Parser.h SingleRotor.cpp SingleRotor.h
        MultiRotor.cpp MultiRotor.h FixedWing.cpp FixedWing.h Hybrid.h Hybrid.cpp)
#