//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_DRONE_H
#define DRONES_DRONE_H
#include "Vector.h"
#include <ostream>
using namespace std;
class Drone {
public:
    Drone(int id, const Vector & place, const Vector & speed);
    Drone():id(-99), place(-99, -99), speed(-99, -99){}
    friend  ostream & operator <<(ostream & os, const Drone & d)
    {
        os<<"(" << d.place.get_x() << ", " << d.place.get_y() << "); ("<< d.speed.get_x() << ", " << d.speed.get_y() << ");  " << d.id << endl;
        return os;
    }
    void move(Vector & globalBest);
    int get_id() const;
    void set_id(int id);

private:
    int id;
    Vector place;
    Vector speed;
    Vector personalBest;



};


#endif //DRONES_DRONE_H
