//
// Created by misha on 13/12/2020.
//

#include "Wood.h"

Wood::Wood(int iter, const Vector & aim):drones(), iter_max(iter), aim(aim), globalBest(100, 100){
    for (int i = 0; i < 42; ++i) {
        for (int j = 0; j < 72; ++j) {
            field[i][j].id.set_x(i);
            field[i][j].id.set_y(j);
        }

    }
}

void Wood::init() {
    for (int i = 0; i < 42; ++i) {
        for (int j = 0; j < 72; ++j) {
            Node * temp = drones.head;
            while((temp=temp->get_next()) != NULL)
            {
                if(temp->get_data().get_place().floored().x == i && temp->get_data().get_place().floored().y == j) {
                    field[i][j]++;
                }
                if((temp->get_data().get_place() - aim).norm() < globalBest.norm())
                    globalBest = temp->get_data().get_place();
            }
        }
    }


}

