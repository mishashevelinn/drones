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
        double x = (d.place.get_x()*100);
        double y = (d.place.get_y()*100);
        x /= 1;
        y /= 1;

        os << Vector(x/100, y/100);
        return os;

    }


    Drone(const Drone &);
    int get_id() const;
    bool move(Vector & globalBest, Square (&squares)[42][72]);
    const Vector &get_place();

    virtual ~Drone();
    Drone & operator=(const Drone & rhs);


private:
    int id;

    Vector place;
    Vector speed;
    Vector personalBest;
    Vector dest;
    double aim_dist;
    Vector square_idx;


};

#endif //DRONES_DRONE_H
