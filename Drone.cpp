//
// Created by misha on 13/12/2020.
//


#include "Drone.h"

#include <cstdlib>

Drone::Drone(const Vector &place, const Vector &speed, const Vector &dest) : place(place), speed(speed),
                                                                             dest(dest), aim_dist(
                Vector(this->place - this->dest).norm()) {
    personalBest = place;
    square_idx = place.floored();
    id++;

}


int Drone::get_id() const {
    return Drone::id;
}


const Vector &Drone::get_place() { return place; }

bool Drone::move(Vector &globalBest, Square (&squares)[42][72]) {
    Vector v_i;

    float r_1 = (float)rand() / (float)RAND_MAX;

    float r_2 = (float)rand() / (float)RAND_MAX;

    Vector s((this->personalBest - this->place) * r_1);
    Vector t((globalBest - place) * r_2);
    Vector r(speed * 0.25);
    v_i = s + t + r;

    place = place + speed;
    speed = v_i;

    if (place.floored() == dest) {
        return true;
    }


    if (place.get_x() > 42)
        place.set_x(42);
    if (place.get_y() > 72)
        place.set_y(42);
    if (place.get_x() < 0)
        place.set_x(0);
    if (place.get_y() < 0)
        place.set_y(0);
    if ((dest - place).norm() < (dest - personalBest).norm())
        personalBest = place;

    if (place.floored() != square_idx) {
        squares[(int) square_idx.get_x()][(int) square_idx.get_y()]--;
        square_idx = place.floored();
        squares[(int) square_idx.get_x()][(int) square_idx.get_y()]++;
    }
    return false;
}
