//
// Created by misha on 13/12/2020.
//
#ifndef DRONES_SQUARE_H
#define DRONES_SQUARE_H
#include "Vector.h"
#include "DroneList.h"



class Square {
public:
    Square();

    void operator++() const
    {
        this->dl++;
    }
    DroneList dl;
};


#endif //DRONES_SQUARE_H
