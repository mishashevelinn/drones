//
// Created by misha on 08/01/2021.
//

#ifndef DRONES_HYBRID_H
#define DRONES_HYBRID_H
#include "FixedWing.h"
#include "SingleRotor.h"
class Hybrid : public FixedWing, public SingleRotor {
public:
    Hybrid();
    Hybrid(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
           int y_min);
     virtual ~Hybrid(){};

};


#endif //DRONES_HYBRID_H
