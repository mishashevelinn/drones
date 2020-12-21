//
// Created by misha on 13/12/2020.
//

#include "Node.h"
/*A Basic Node as Part of DroneList*/
Node::Node() {
        next = NULL;
        prev = NULL;
}


Node *Node::get_next() {
        return next;
}

Node *Node::get_prev() {
        return prev;
}

Drone &Node::get_data() {
        return data;
}

Node::~Node() {

}



