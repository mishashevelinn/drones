//
// Created by misha on 13/12/2020.
//

#include "Wood.h"


/*Wood keeps 2D array of squares
 * init -- calculates initial values of squares counters and
 * defined global best.*/
Wood::Wood(int iter, const Vector &aim, int x_min, int x_max, int y_min, int y_max):
drones(), iter_max(iter), aim(aim), globalBest(), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max){
    field = new Square*[(x_max - x_min) * (y_max - y_min)];
    for (int i = 0; i < y_max - y_min; ++i) {
        field[i] = new Square[(x_max - x_min)];
        for (int j = 0; j < x_max - x_min; ++j) {
            field[i][j].setVector(Vector(i+x_min, j+y_min));
        }
    }
}

void Wood::init() {
    for (int i = 0; i < y_max - x_min ; i++) {
        for (int j = 0; j < x_max - y_min  ; j++) {
                Recognize find(i + x_min, j + y_min);
                int temp = 0;
                drones->iterate(find, drones->root, temp);
                field[i][j].set_counter(temp);
            }
        }
    find_best(drones->root);
}
void Wood::find_best(BstNode<Drone> * node)
{
    if(node == 0)
        return;
    find_best(node->getLeft());
    if((node->getData()->get_place() - aim).norm() < (globalBest - aim).norm()) {
        globalBest = node->getData()->get_place();
    }
    find_best(node->getRight());
}



Wood::~Wood(){
    delete drones;
    for (int i = 0; i < y_max; ++i) {
        delete [] field[i];
    }
    delete[] field;
}

Wood::Wood(const Wood &other) {
}



