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
#include <iostream>

Drone::Drone(const Vector &place, const Vector &speed, const Vector &dest, int x_max, int y_max, int x_min, int y_min) :
x_max(x_max), y_max(y_max), x_min(x_min), y_min(y_min), place(place), speed(speed),dest(dest), aim_dist(Vector(this->place - this->dest).norm()) , id(++serial){
    personalBest = place;
    square_idx = place.floored();

}

Drone::~Drone(){}


int Drone::get_id() const {
    return Drone::serial;
}


const Vector &Drone::get_place() { return place; }

bool Drone::move(Vector &globalBest, Square** squares) {
    Vector v_i;
    /*Calculating next speed value according to a formula*/
    float r_1 = (float)rand() / (float)RAND_MAX;

    float r_2 = (float)rand() / (float)RAND_MAX;

    Vector s((this->personalBest - this->place) * r_1);
    Vector t((globalBest - place) * r_2);
    Vector r(speed * 0.25);
    v_i = s*a + t*b + r*c;

    /*updating drone's position with respect tu current speed*/
    place = place + speed;
    /*updating speed*/
    speed = v_i;


    /*Drone is in destination square -> end of simulation*/
    if (place.floored() == dest) {
        return true;
    }


    /*Dirichlet boundary condition*/
    if (place.get_x() > x_max - 1)
        place.set_x(x_max - 1);
    if (place.get_y() > y_max - 1)
        place.set_y(y_max - 1);
    if (place.get_x() < x_min)
        place.set_x(x_min);
    if (place.get_y() < y_min)
        place.set_y(y_min);

    /*If cuurent position is closer to the aim than ever, update personal best*/
    if ((dest - place).norm() < (dest - personalBest).norm())
        personalBest = place;
    if( (dest - place).norm() < (dest - globalBest).norm())
        globalBest = place;

    /*Condition is true if Drone left its square. Decrement old square's
     * counter and increment the new one's*/
    if (place.floored() != square_idx) {
        int x_index = (int)square_idx.get_x();
        int y_index = (int)(square_idx.get_y());
        squares[x_index][y_index]--;
        square_idx = place.floored();
        //cout << (int)square_idx.get_x() << " " << (int)square_idx.get_y() << endl;
        squares[(int)square_idx.get_x()][(int)square_idx.get_y()]++;
    }
    return false;
}

Drone::Drone(const Drone & other){
    *this = other;
}

Drone &Drone::operator=(const Drone & rhs) {
    this->serial = rhs.serial;
    this->speed = rhs.speed;
    this->place = rhs.place;
    this->aim_dist = rhs.aim_dist;
    this->dest = rhs.dest;
    this->personalBest = rhs.personalBest;
    this->square_idx = rhs.square_idx;
    this->x_max = rhs.x_max;
    this->x_min = rhs.x_min;
    this->y_min = rhs.y_min;
    this->y_max = rhs.y_max;
    a = rhs.a;     b = rhs.b;   c = rhs.c;    type = rhs.type;
    id = rhs.get_id();
return *this;}

bool Drone::operator<(const Drone &rhs) const {
    return id < rhs.id;
}

bool Drone::operator>(const Drone &rhs) const {
    return rhs < *this;
}

bool Drone::operator<=(const Drone &rhs) const {
    return !(rhs < *this);
}

bool Drone::operator>=(const Drone &rhs) const {
    return !(*this < rhs);
}

bool Drone::operator==(const Drone &rhs) const {
    return id == rhs.id;
}

bool Drone::operator!=(const Drone &rhs) const {
    return !(rhs == *this);
}
int Drone:: serial = 0;