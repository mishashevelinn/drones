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
    cout << w.globalBest;
    Node * n;



    int num_iter = 0;
    bool found = false;
    while(true) {
        n = w.drones.head;
        while ((n->get_next()) != w.drones.tail) {
            n = n->get_next();
            if(n->get_data().move(w.globalBest, w.field, found))
                goto fin;
            if((n->get_data().get_place() - w.aim).norm() < w.globalBest.norm())
                w.globalBest = n->get_data().get_place();

        }
        if(num_iter == 120)
            break;
        num_iter++;
        cout << num_iter << endl;
    }
    fin:
    cout << num_iter;
    cout << "game over" <<  endl;
    cout << w.drones;
    cout << w.aim;
    for (int i = 0; i < 42; ++i) {
        for (int j =0; j < 72; i++) {
            cout << w.field[i][j];

        }
        cout << endl;

    }

//float f = (float)rand()/RAND_MAX;
//cout << f;

}
