//
// Created by misha on 08/01/2021.
//

#ifndef DRONES_FIXEDWING_H
#define DRONES_FIXEDWING_H


#include "Drone.h"

class FixedWing : virtual public Drone{
public:
    FixedWing();
    FixedWing(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
              int y_min);
    virtual ~FixedWing(){};

};


#endif //DRONES_FIXEDWING_H
