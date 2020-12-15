//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_DRONELIST_H
#define DRONES_DRONELIST_H

#include <cstdio>
#include "Drone.h"
#include "Node.h"
#include <ostream>
using namespace std;

class DroneList {
public:


    DroneList();


    void insert(Drone new_data);


    virtual ~DroneList();

    void operator++()
    {
        head->get_data().set_id(head->get_data().get_id() + 1);
    }

    friend ostream & operator<<(ostream & os, const DroneList & rhs)
    {
        Node * temp = rhs.head;
        while ((temp = temp->get_next()) !=rhs.tail)
        {
            os << temp->get_data();
        }
        return os;
    }

    Node * head;
    Node * tail;

};


#endif //DRONES_DRONELIST_H
