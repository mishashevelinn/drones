//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_WOOD_H
#define DRONES_WOOD_H

#include "DroneList.h"
#include "Square.h"
#include <iostream>
using namespace std;
class Wood {
public:
    Wood(int iter, const Vector &aim);
    void init();




    friend ostream &operator<<(ostream &os,const  Wood &w) {

            for (int i = 0; i < 42; ++i) {
                for (int j = 0; j < 72; ++j) {
                    if(w.field[i][j].get_counter() == 0)
                        continue;
                    os << "(" << i << " ," << j << "):" << endl;
                    Node * temp = w.drones.head;
                    while((temp=temp->get_next()) != NULL)
                    {
                        if(temp->get_data().get_place().floored().get_x() == i && temp->get_data().get_place().floored().get_y() == j) {
                            os << "drone No.:" << temp->get_data().get_id() << ", ";
                        }
                    }
                    os << endl;
                    os<< "total drones in sqare : " << w.field[i][j].get_counter() << endl;
                }
            }
        return os;
    }
    DroneList & get_drones() {}

private:

    DroneList drones;
    int iter_max;
    Vector aim;
    Vector globalBest;
    Square field[42][72];



};


#endif //DRONES_WOOD_H
