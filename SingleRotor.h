//
// Created by misha on 08/01/2021.
//

#ifndef DRONES_SINGLEROTOR_H
#define DRONES_SINGLEROTOR_H


#include "Drone.h"

class SingleRotor : virtual public Drone{

public:
    SingleRotor();

    SingleRotor(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
                int y_min);

    virtual ~SingleRotor();

};


#endif //DRONES_SINGLEROTOR_H
