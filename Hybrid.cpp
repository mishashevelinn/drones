//
// Created by misha on 08/01/2021.
//

#include "Hybrid.h"

Hybrid::Hybrid() :Drone(), FixedWing(), SingleRotor(){
    a=0.01;     b = -0.1;       c = -0.25;  type = 'H';

}

Hybrid::Hybrid(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min, int y_min)
        : Drone(place, speed, dest, x_max, y_max, x_min, y_min) {
    a=0.01;     b = -0.1;       c = -0.25;  type = 'H';


}
