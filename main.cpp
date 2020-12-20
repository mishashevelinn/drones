#include <iostream>

#include "Parser.h"
#include "Wood.h"
int main(int argc, char* args[]) {

    if(argc != 4) {
        cerr << INV_INPUT << endl;
        return 0;
    }

    srand(time(NULL));

    DroneList dl;
    Parser p(args[1], args[2]);

//    fstream fs;
//    fs.open(args[1]);
//    string line;
//    if (!fs) {
//        return 0;
//    }
//    string buff;
//    int counter = 0;
//    while (getline(fs, buff)) {
//        counter++;
//    }
//    if (counter != 2) {
//        cerr << INV_INPUT << endl;
//        return 0;
//    }



    int i = 0;
    if(!p.parse_init(i)) {
        cerr << INV_INPUT << endl;
        return 0;
    }
    if(!p.parse_drones(dl))
    {
        cerr << INV_INPUT << endl;
        return 0;
    }

    Wood w(i,p.aim);



    w.drones = dl;

    w.init();

    ofstream ofs;
    ofs.open(args[3]);

    if(i == 0)
    {
        ofs << w.iter_max << endl;
        ofs << w.drones;
        return 0;
    }
    Node * n;




    int num_iter = 0;
    while(true) {
        n = w.drones.head;
        while ((n->get_next()) != w.drones.tail) {
            n = n->get_next();
            if(n->get_data().move(w.globalBest, w.field))
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
