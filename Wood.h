//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_WOOD_H
#define DRONES_WOOD_H

#include "Square.h"
#include <iostream>
using namespace std;
class Wood {
public:
    friend ostream & operator <<(ostream & os, const Wood & w)
    {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << "Square No : (" << i << ", " << j << ") :"<< w.field[i][j].dl;
            }
        }
    }
    Square field[10][10];
    Vector globalBest;






};


#endif //DRONES_WOOD_H
