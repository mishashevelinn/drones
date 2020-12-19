//
// Created by misha on 13/12/2020.
//



#include <iostream>
#include "Drone.h"
#include "Square.h"
#include <time.h>
Drone::Drone(const Vector &place, const Vector &speed, const Vector &dest) : place(place), speed(speed),
                                                                             dest(dest), aim_dist(
                Vector(this->place - this->dest).norm()) {
    personalBest = (this->dest - this->place);
    square_idx = place.floored();
    id++;

}


int Drone::get_id() const {
    return Drone::id;
}


const Vector &Drone::get_place() { return place; }

bool Drone::move(Vector &globalBest, Square (&squares)[42][72], bool &found) {
    cout << *this << endl;
    Vector v_i;

    float r_1 = (float)rand() / RAND_MAX;

    float r_2 = (float)rand() / RAND_MAX;
    cout << "r1=" << r_1 <<"; r2="<<r_2<<"global best = "<<globalBest <<endl;
    Vector v((this->personalBest - this->place) * r_1);
    Vector t((globalBest - place) * r_2);
    Vector r(speed * 0.25);
    v_i = v + t + r;
    speed = v_i;
    place = place + v_i;
    if (place.floored() == dest) {
        cout << "winner is :" << *this << endl;
       // found = true;
        return true;
    }


    cout << "after moving: " << endl;
    cout << *this << endl;

    if (place.x > 42)
        place.x = 42;
    if (place.y > 72)
        place.y = 72;
    if (place.x < 0)
        place.x = 0;
    if (place.y < 0)
        place.y = 0;
    if ((dest - place).norm() < personalBest.norm())
        personalBest = place;

    if (place.floored() != square_idx) {
        squares[(int) square_idx.x][(int) square_idx.y]--;
        square_idx = place.floored();
        squares[(int) square_idx.x][(int) square_idx.y]++;
    }
    return false;
}
