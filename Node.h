//
// Created by misha on 13/12/2020.
//

#ifndef DRONES_NODE_H
#define DRONES_NODE_H
#include <cstdlib>
#include "Drone.h"

using namespace std;


class Node {
public:
    Node(const Node & other)
    {
        this->data = other.data;
        this->next = other.next;
        this->prev = other.prev;
    }
    Node & operator=(const Node & rhs)
    {
        this->data = rhs.data;
        this->prev = rhs.prev;
        this->next = rhs.next;

        return *this;
    }
    Node();

    virtual ~Node();

    Node * next;
    Node * prev;
    Drone data;

    Node * get_next();


    Node * get_prev();

    Drone & get_data();

};


#endif //DRONES_NODE_H
