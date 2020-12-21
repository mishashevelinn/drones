//
// Created by misha on 13/12/2020.
//
/**Drone class:
 *Stores info about :
 * --drone's position
 * --drone's serial number
 * --drone's speed
 *Drone move functionality
 * Function move() gets a reference to an array of counters
 * And updates it according to square, drone currently in.
 */

#include "Drone.h"

#include <cstdlib>

Drone::Drone(const Vector &place, const Vector &speed, const Vector &dest) : place(place), speed(speed),
                                                                             dest(dest), aim_dist(
                Vector(this->place - this->dest).norm()) {
    personalBest = place;
    square_idx = place.floored();
    id++;

}

Drone::~Drone(){}


int Drone::get_id() const {
    return Drone::id;
}


const Vector &Drone::get_place() { return place; }

bool Drone::move(Vector &globalBest, Square (&squares)[42][72]) {
    Vector v_i;
    /*Calculating next speed value according to a formula*/
    float r_1 = (float)rand() / (float)RAND_MAX;

    float r_2 = (float)rand() / (float)RAND_MAX;

    Vector s((this->personalBest - this->place) * r_1);
    Vector t((globalBest - place) * r_2);
    Vector r(speed * 0.25);
    v_i = s + t + r;

    /*updating drone's position with respect tu current speed*/
    place = place + speed;
    /*updating speed*/
    speed = v_i;


    /*Drone is in destination square -> end of simulation*/
    if (place.floored() == dest) {
        return true;
    }


    /*Dirichlet boundary condition*/
    if (place.get_x() > 42)
        place.set_x(42);
    if (place.get_y() > 72)
        place.set_y(42);
    if (place.get_x() < 0)
        place.set_x(0);
    if (place.get_y() < 0)
        place.set_y(0);

    /*If cuurent position is closer to the aim than ever, update personal best*/
    if ((dest - place).norm() < (dest - personalBest).norm())
        personalBest = place;

    /*Condition is true if Drone left its square. Decrement old square's
     * counter and increment the new one's*/
    if (place.floored() != square_idx) {
        squares[(int) square_idx.get_x()][(int) square_idx.get_y()]--;
        square_idx = place.floored();
        squares[(int) square_idx.get_x()][(int) square_idx.get_y()]++;
    }
    return false;
}

Drone::Drone(const Drone & other){
    *this = other;
}

Drone &Drone::operator=(const Drone & rhs) {
    this->id = rhs.id;
    this->speed = rhs.speed;
    this->place = rhs.place;
    this->aim_dist = rhs.aim_dist;
    this->dest = rhs.dest;
    this->personalBest = rhs.personalBest;
    this->square_idx = rhs.square_idx;
return *this;}
