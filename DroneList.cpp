//
// Created by misha on 13/12/2020.
//

#include "DroneList.h"

DroneList::DroneList() {
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
}

void DroneList::insert(Drone new_data) {
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;

    }
}

DroneList::~DroneList() {
    {
        Node * temp;
        temp = head;
        while ((temp->get_next()) != NULL)
        {
            Node * del = temp;
            temp = temp->get_next();
            delete(del);
        }
    }
}
