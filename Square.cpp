//
// Created by misha on 13/12/2020.
//

#include "Square.h"

/*A simple class to store integer indexes.
 * Contains counter to keep track of how
 * many drones currently are in the square*/
Square::Square()  : id(0, 0), counter(0){}

int Square::get_counter() const {
    return counter;
}

Vector Square::get_id() const {
    return id;
}

Square::Square(const Square &other) {
    this->id = other.id;
    this->counter = other.counter;
}
void Square::set_counter(int i){
    counter = i;
}

void Square:: setVector(const Vector & v){
    id = v;
}

Square::~Square() {

}


