//
// Created by misha on 08/01/2021.
//

#include "FixedWing.h"

FixedWing::FixedWing():Drone() {
    a = 0.25;     b = 1;     c = 1; type='W';

}

FixedWing::FixedWing(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
                     int y_min) : Drone(place, speed, dest, x_max, y_max, x_min, y_min) {
    a = 0.25;     b = 1;     c = 1; type='W';

}
