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
    int x_max, y_max, x_min, y_min;
    Drone(const Vector & place, const Vector & speed, const Vector & dest, int x_max, int y_max, int x_min, int y_min);
    Drone():place(-99, -99), speed(-99, -99), a(0.25), b(1), c(1), type('D'), id(++serial){}

    friend  ostream & operator <<(ostream & os, const Drone & d)
    {
        double x = (d.place.get_x()*100);
        double y = (d.place.get_y()*100);
        x /= 1;
        y /= 1;

        os << d.type << " " << Vector(x/100, y/100);
        return os;

    }


    Drone(const Drone &);
    int get_id() const;
    bool move(Vector & globalBest, Square **);
    const Vector &get_place();

    virtual ~Drone();
    Drone & operator=(const Drone & rhs);

    bool operator<(const Drone &rhs) const;

    bool operator>(const Drone &rhs) const;

    bool operator<=(const Drone &rhs) const;

    bool operator>=(const Drone &rhs) const;

    bool operator==(const Drone &rhs) const;

    bool operator!=(const Drone &rhs) const;
    float a, b, c;
    char type;


private:
    static int serial;
     int id;

    Vector place;
    Vector speed;
    Vector personalBest;
    Vector dest;
    double aim_dist;
    Vector square_idx;


};


#endif //DRONES_DRONE_H
