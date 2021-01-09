#include <iostream>

#include "Parser.h"
#include "Wood.h"


/***Driver Code***/
void iterate(Wood & w, BstNode<Drone> * root, bool & flag)
{
    if(root == 0)
        return;
    iterate(w, root->getLeft(), flag);
    if(root->getData()->move(w.get_global_best(), w.field))
        flag = true;
    iterate(w, root->getRight(), flag);

}

int main(int argc, char* args[]) {
    Vector v;
    int k;
    cout << sizeof (v) << endl;
    cout << sizeof (k);

/*Checking number of arguments*/
    if (argc != 4) {
        cerr << INV_INPUT << endl;
        return 0;
    }
    /*setting seed for rand() to be current time*/
    srand(time(NULL));
    Tree<Drone> *dl = new Tree<Drone>;
    Parser p(args[1], args[2]);

    /*parsing simulation settings*/
    int i = 0;
    if (!p.parse_init(i)) {
        cerr << INV_INPUT << endl;
        return 0;
    }
    /*Parsing drones positions info*/

    if (!p.parse_drones(dl)) {
        cerr << INV_INPUT << endl;
        return 0;
    }

    /*initializing wood with max number of iterations
     * and destination*/
    Wood w(i, p.aim, p.x_min, p.x_max, p.y_min, p.y_max);
    w.set_drones(dl);
    w.init();

    //opening a file for writing
    ofstream ofs;
    ofs.open(args[3]);


    /*If number of iterations is zero, writing
     * to a result file drones initial position*/
    if (i == 0) {
        ofs << w.get_iter_max() << endl;
        ofs << w.get_drones();
        return 0;
    }



    /*Main while loop:
     * iterates over all drones and moves them.
     * updates glo*/
    int num_iter = 0;


    while (true) {
        bool flag = false;
        iterate(w, w.drones->root, flag);
        if (flag) {
            ofs << num_iter << endl;
            ofs << w.drones;
            return 0;
        }
        /*Case when maximal number of iterations, defined in settings file is reached*/
        if (num_iter == w.get_iter_max()) {
            ofs << num_iter << endl;
            ofs << w.drones;
            return 0;
        }

        num_iter++;
    }
    }