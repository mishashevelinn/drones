#include <iostream>

#include "Parser.h"
#include "Wood.h"
int main(int argv, char* args[]) {
    if(argv != 4) {
        cerr << INVINP << endl;
        return 0;
    }

    srand(time(NULL));
    Wood w(10000,Vector(10.5, 2.5));
    DroneList dl;
    Parser p(args[1], args[2]);
    p.parse_drones(dl);

    w.drones = dl;

    w.init();
    cout << w.globalBest;
    Node * n;


    ofstream ofs;
    ofs.open(args[3]);

    int num_iter = 0;
    bool found = false;
    while(true) {
        n = w.drones.head;
        while ((n->get_next()) != w.drones.tail) {
            n = n->get_next();
            if(n->get_data().move(w.globalBest, w.field, found))
                goto fin;

            float curr_aim_dist;
            curr_aim_dist = (n->get_data().get_place() - w.aim).norm();
            float best_dist = (w.globalBest - w.aim).norm();
            if((curr_aim_dist < best_dist))
                w.globalBest = n->get_data().get_place();
            if(n->get_data().get_place().floored() == w.aim) {
                //cout << "FIN" << endl;
                ofs << num_iter << endl;
                ofs << w.drones;
                return 0;
            }
            }
        if(num_iter == w.iter_max) {
            ofs << num_iter << endl;
            ofs << w.drones;
            return 0;
        }

        num_iter++;
    }
    fin:
    return 0;



//float f = (float)rand()/RAND_MAX;
//cout << f;

}
