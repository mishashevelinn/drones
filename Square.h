//
// Created by misha on 13/12/2020.
//
#ifndef DRONES_SQUARE_H
#define DRONES_SQUARE_H
#include "Vector.h"

class Square {
public:
    Square(int i, int j){
        id.x = i;
        id.y = j;
    }
    friend ostream & operator<<(ostream & os, const Square & rhs)
    {
        os <<"Square n " << rhs.id << " contains " << rhs.counter << " drones.";
        return os;
    }

    Square() : id(0, 0), counter(0){}
    const  Square  operator++(int){
        counter++;
        return *this;
    }

    const Square operator--(int){
        counter--;
        return  *this;
    }

    int counter;
    Vector id;
};


#endif //DRONES_SQUARE_H
