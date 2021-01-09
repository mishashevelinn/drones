//
// Created by misha on 08/01/2021.
//

#ifndef DRONES_MULTIROTOR_H
#define DRONES_MULTIROTOR_H
#include "Drone.h"

class MultiRotor : public Drone{
public:
    MultiRotor();
    MultiRotor(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
                int y_min);
    virtual ~MultiRotor(){};
};


#endif //DRONES_MULTIROTOR_H
