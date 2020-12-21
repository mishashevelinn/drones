//
// Created by misha on 13/12/2020.
//

#include "Wood.h"


/*Wood keeps 2D array of squares
 * init -- calculates initial values of squares counters and
 * defined global best.*/
Wood::Wood(int iter, const Vector & aim):drones(), iter_max(iter), aim(aim), globalBest(){
    for (int i = 0; i < 42; ++i) {
        for (int j = 0; j < 72; ++j) {
            field[i][j].get_id().set_x(i);
            field[i][j].get_id().set_y(j);
        }

    }
}

void Wood::init() {
    for (int i = 0; i < 42; ++i) {
        for (int j = 0; j < 72; ++j) {
            Node * temp = drones.head;
            while((temp=temp->get_next()) != NULL)
            {
                if(temp->get_data().get_place().floored().get_x() == i && temp->get_data().get_place().floored().get_y() == j) {
                    field[i][j]++;
                }

            }
        }
    }
    globalBest = drones.head->get_next()->get_next()->get_data().get_place();


}

Wood::~Wood() {

}

Wood::Wood(const Wood &other) {

}

