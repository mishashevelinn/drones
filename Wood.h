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
    virtual ~Wood();

    Wood(int iter, const Vector &aim);
    Wood(const Wood & other);
    Wood & operator=(const Wood & rhs)
    {
        this->aim = rhs.aim;
        this->iter_max = rhs.iter_max;
        this->globalBest = rhs.globalBest;
        this->drones = rhs.drones;
        for (int i = 0; i < 42; ++i) {
            for (int j = 0; j < 72; ++j) {
                this->field[i][j] = rhs.field[i][j];
            }

        }
return *this;   }
    void init();

    int operator()(int i, int j){
        return field[i][j].get_counter();
    }


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
    int get_iter_max(){return iter_max;}
    const DroneList & get_drones() const  {return drones;}
    void set_drones(DroneList & other) { drones = other;}
     Vector & get_global_best() {return globalBest;}
    const Vector & get_aim() const {return aim;}
    void set_global_best(const Vector & other){ globalBest = other;}
    Square field[42][72];


private:

    DroneList drones;
    int iter_max;
    Vector aim;
    Vector globalBest;



};


#endif //DRONES_WOOD_H
