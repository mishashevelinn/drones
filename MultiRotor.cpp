//
// Created by misha on 08/01/2021.
//

#include "MultiRotor.h"

MultiRotor::MultiRotor():Drone() {
    a = 0.05;     b = 0.1;     c = 0; type='M';
    }



MultiRotor::MultiRotor(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min,
                       int y_min) : Drone(place, speed, dest, x_max, y_max, x_min, y_min) {
    a = 0.05;     b = 0.1;     c = 0; type='M';

}
