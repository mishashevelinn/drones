//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_VECTOR_H
#define DRONES_VECTOR_H

#include <cmath>
#include <ostream>
using namespace std;

class Vector {
public:
    Vector(double x, double y);

    Vector();

    Vector(const Vector &other);

    Vector &operator=(const Vector &rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    bool operator==(const Vector &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Vector &rhs) const{
        return !this->operator==(rhs);
    }
    Vector floored() const;
    Vector operator*(float scalar) const
    {
        return  Vector(scalar*x, scalar*y);
    }
    Vector  operator+(Vector & rhs) const
    {
        return Vector(x+rhs.x, y + rhs.y);

    }
    Vector operator-(const Vector & rhs) const
    {
        Vector temp = rhs*(-1);
        return *this + temp;
    }
    friend ostream & operator<<(ostream  & os, const Vector & rhs)
    {
        os << rhs.x <<" " << rhs.y;
        return os;
    }
    double get_x() const;
    double get_y()const;
    void set_x(double x);
    void set_y(double y);
    double norm() const;

    double x;
    double y;


};


#endif //DRONES_VECTOR_H
