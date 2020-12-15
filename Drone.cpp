//
// Created by misha on 13/12/2020.
//

#include "Drone.h"
Drone :: Drone(int id, const Vector & place, const Vector & speed):id(id), place(place), speed(speed) {}

void Drone::move(Vector &globalBest) {
   // Vector V_i = 0.25*

}

int Drone::get_id() const {
    return id;
}

void Drone::set_id(int id) {
    this->id = id;

}
