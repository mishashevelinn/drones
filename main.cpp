#include <iostream>

#include "Parser.h"
#include "Wood.h"
int main() {
    Wood w(10,Vector(4,4));
    DroneList dl;
    Parser p("init", "drones_init");
    p.parse_drones(dl);


    w.drones = dl;

    w.init();
    Node * n;
    n = w.drones.head;

//    cout << w.drones;
//    Node * d = w.drones.head->get_next();
//    int end = 0;
//    d->get_data().move(w.globalBest, reinterpret_cast<int **>(w.field), end);
//    cout << d->get_data();
//    d->get_data().move(w.globalBest, reinterpret_cast<int **>(w.field), end);
//    cout << w.drones;

    int num_iter = 0;
    bool found = false;
    while(!found) {
        while ((n->get_next()) != w.drones.tail) {
            n = n->get_next();
            n->get_data().move(w.globalBest, reinterpret_cast<int **>(w.field), found);
            cout << w.drones;
            cout << endl;

        }
        num_iter++;
        cout << num_iter << endl;
        if(num_iter == 3)
        {
            break;

        }
    }
    cout << "game over" <<  endl;
    cout << w.drones;
    cout << w.aim;

}
