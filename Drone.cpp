//
// Created by misha on 13/12/2020.
//



#include "Drone.h"


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

bool Drone::move(Vector &globalBest, int **squares, bool &found) {
    Vector v_i;
    srand(time(0));
    double r_1 = rand() / RAND_MAX;
    srand(time(0));
    double r_2 = rand() / RAND_MAX;
    Vector v((this->personalBest - this->place) * r_1);
    Vector t((globalBest - place) * r_2);
    Vector r(speed * 0.25);
    v_i = v + t + r;
    speed = v_i;
    place = place + v_i;
    if (place.floored() == dest) {
        found = 1;
        return true;
    }

    if (place.x > 42)
        place.x = 42;
    if (place.y > 72)
        place.y = 72;
    if (place.x < 0)
        place.x = 0;
    if (place.y < 0)
        place.y = 0;
    if ((dest - place).norm() < personalBest.norm())
        personalBest = (dest - place);

    if (place.floored() != square_idx) {
        squares[(int) square_idx.x][(int) square_idx.y]--;
        square_idx = place.floored();
        squares[(int) square_idx.x][(int) square_idx.y]++;
    }
}