//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_WOOD_H
#define DRONES_WOOD_H

#include "BST.h"
#include "Square.h"
#include "Drone.h"
#include <iostream>
using namespace std;
class Wood {
public:
    virtual ~Wood();

    Wood(int iter, const Vector &aim, int x_min, int x_max, int y_min, int y_max);
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
        return *this;
    }

    void init();

    int operator()(int i, int j){
        return field[i][j].get_counter();
    }


    friend ostream &operator<<(ostream &os,const  Wood &w) {
        os << w.drones << endl;
        for (int i = 0; i < w.x_max - w.x_min; ++i) {
            if(i != 0)
            os << endl << "_____|_____|_____|_____|" << endl;
            for(int j = 0; j < w.y_max - w.y_min; ++j) {
                os << w.field[i][j];
            }

        }
    }


    int get_iter_max(){return iter_max;}
    const Tree<Drone> * get_drones() const  {return drones;}
    void set_drones(Tree<Drone> * other) { drones = other;}
    Vector & get_global_best() {return globalBest;}
    const Vector & get_aim() const {return aim;}
    void set_global_best(const Vector & other){ globalBest = other;}
    Square** field;
    Tree<Drone> * drones;
    void find_best(BstNode<Drone> *node);
    int x_min, x_max, y_min, y_max;


private:


    int iter_max;
    Vector aim;
    Vector globalBest;



};

//class Move{
//public:
//    Vector v;
//    Wood w;
//    Move(Vector & v, Wood & w) : v(v), w(w){}
//    bool operator()(Drone * d){
//        return d->move(v, w.field);
//    }
//};
class Recognize{
public:
    int i, j;
    Recognize(int i, int j): i(i), j(j){}

    bool operator()(Drone * d){
        return (d->get_place().floored().get_x() == i && d->get_place().floored().get_y() == j);
    }
};


#endif //DRONES_WOOD_H
