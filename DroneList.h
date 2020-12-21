//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_DRONELIST_H
#define DRONES_DRONELIST_H


#include "Drone.h"
#include "Node.h"

using namespace std;

class DroneList {
public:


    DroneList();
    DroneList(const DroneList & other);
    DroneList & operator=(const DroneList & rhs)
    {
        this->head = rhs.head;
        this->tail = rhs.tail;
        return *this;
    }


    void insert(Drone new_data);


    virtual ~DroneList();


    friend ostream & operator<<(ostream & os, const DroneList & rhs)
    {
        Node * temp = rhs.tail;
        while ((temp = temp->get_prev()) != rhs.head)
        {
            os << temp->get_data() << endl;
        }
        return os;
    }

    const Drone & get_head() const { return head->get_data();}

    Node * head;
    Node * tail;

};


#endif //DRONES_DRONELIST_H
