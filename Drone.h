//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_DRONE_H
#define DRONES_DRONE_H
#include "Vector.h"
#include "Square.h"
#include <ostream>

using namespace std;
class Drone {
public:
    Drone(const Vector & place, const Vector & speed, const Vector & dest);
    Drone():place(-99, -99), speed(-99, -99){}
    friend  ostream & operator <<(ostream & os, const Drone & d)
    {
        os << "drone N: " << d.id<< " ";
        os<<"(" << d.place.get_x() << ", " << d.place.get_y() << "); ("<< d.speed.get_x() << ", " << d.speed.get_y() << ");  " << endl;
        return os;
    }
    int get_id() const;
    bool move(Vector & globalBest, Square (&squares)[42][72], bool & found);
    const Vector &get_place();
    int id;

private:

    Vector place;
    Vector speed;
    Vector personalBest;
    Vector dest;
    double aim_dist;
    Vector square_idx;


};

#endif //DRONES_DRONE_H
