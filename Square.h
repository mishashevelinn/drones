//
// Created by misha on 13/12/2020.
//
#ifndef DRONES_SQUARE_H
#define DRONES_SQUARE_H
#include "Vector.h"

class Square {
public:

    Square(const Square & other);
    Square & operator=(const Square & rhs){
        this->counter = rhs.counter;
        this->id = rhs.id;
        return *this;
    }

    virtual ~Square();

    friend ostream & operator<<(ostream & os, const Square & rhs)
    {
        os <<"Square n " << rhs.id << " contains " << rhs.counter << " drones.";
        return os;
    }

    Square();

    const  Square  operator++(int){
        counter++;
        return *this;
    }

    const Square operator--(int){
        counter--;
        return  *this;
    }

    const Square operator++()
    {
        ++counter;
        return *this;
    }
    const Square operator--()
    {
        --counter;
        return *this;
    }

    int get_counter() const;
    Vector get_id() const;

private:
    Vector id;
    int counter;


};


#endif //DRONES_SQUARE_H
