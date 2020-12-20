//
// Created by misha on 13/12/2020.
//

#include "Square.h"


Square::Square()  : id(0, 0), counter(0){}

int Square::get_counter() const {
    return counter;
}

Vector Square::get_id() const {
    return id;
}


