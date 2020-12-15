//
// Created by misha on 13/12/2020.
//

#include "DroneList.h"

DroneList::DroneList() {
    {
        head = new Node();
        tail = new Node();
        head->data.set_id(0);
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
        head->next = new_node;
        head->next->prev = new_node;
        head->get_data().set_id(head->get_data().get_id() + 1);
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
