//
// Created by misha on 13/12/2020.
//

#include "Vector.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector() :x(0),y(0) {}

Vector::Vector(const Vector &other) {
    this->x = other.x;
    this->y= other.y;
}
Vector Vector::floored() const {
        return Vector(floor(x), floor(y));
}
double Vector::get_x() const {
    return x;
}
double Vector::get_y() const {
    return y;
}
void Vector::set_x(double x) {
    this->x = x;
}
void Vector::set_y(double y) {
    this->y = y;
}


double Vector::norm() const {
    return sqrt((get_x())*get_x() + get_y()*get_y());
}

