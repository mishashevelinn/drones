#include <iostream>

#include "Parser.h"
#include "BST.h"
#include "Wood.h"


/***Driver Code***/
int main(int argc, char* args[]) {
    Tree<int> * t = new Tree<int>();


    for (int i = 0; i < 10; ++i) {
        int * j = (int*)malloc(sizeof(int));
        *j = i;


        t->insert(j);
    }
    cout << *t;



///*Checking number of arguments*/
//    if(argc != 4) {
//        cerr << INV_INPUT << endl;
//        return 0;
//    }
//    /*setting seed for rand() to be current time*/
//    srand(time(NULL));
//    DroneList dl;
//    Parser p(args[1], args[2]);
//
//    /*parsing simulation settings*/
//    int i = 0;
//    if(!p.parse_init(i)) {
//        cerr << INV_INPUT << endl;
//        return 0;
//    }
//    /*Parsing drones positions info*/
//    if(!p.parse_drones(dl))
//    {
//        cerr << INV_INPUT << endl;
//        return 0;
//    }
//
//    /*initializing wood with max number of iterations
//     * and destination*/
//    Wood w(i,p.aim);
//    w.set_drones(dl);
//    w.init();
//
//    //opening a file for writing
//    ofstream ofs;
//    ofs.open(args[3]);
//
//
//    /*If number of iterations is zero, writing
//     * to a result file drones initial position*/
//    if(i == 0)
//    {
//        ofs << w.get_iter_max() << endl;
//        ofs << w.get_drones();
//        return 0;
//    }
//
//
//
//    /*Main while loop:
//     * iterates over all drones and moves them.
//     * updates glo*/
//    const DroneList & drones = w.get_drones();
//    int num_iter = 0;
//    Node * n;
//    while(true) {
//        n = drones.head;
//        while ((n->get_next()) != drones.tail) {
//            n = n->get_next();
//            if(n->get_data().move(w.get_global_best(), w.field))
//                goto fin;
//
//            /*calculating current distance from destination
//             * comparing to global best's distance from destination
//             * if curent distance is smaller, update global best*/
//            float curr_aim_dist;
//            curr_aim_dist = (n->get_data().get_place() - w.get_aim()).norm();
//            float best_dist = (w.get_global_best() - w.get_aim()).norm();
//
//            if((curr_aim_dist < best_dist))
//                w.set_global_best(n->get_data().get_place());
//            /*Case when drone reaches the destination*/
//            if(n->get_data().get_place().floored() == w.get_aim()) {
//                ofs << num_iter << endl;
//                ofs << drones;
//                return 0;
//            }
//
//            }
//        /*Case when maximal number of iterations, defined in settings file is reached*/
//        if(num_iter == w.get_iter_max()) {
//            ofs << num_iter << endl;
//            ofs << drones;
//            return 0;
//        }
//
//        num_iter++;
//    }
//    fin:



    return 0;

}
