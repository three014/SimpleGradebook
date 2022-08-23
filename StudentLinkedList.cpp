#include <iostream>
#include "StudentLinkedList.hpp"

void Gradebook::StudentLinkedList::remove(double item)
{
    if (head != nullptr && std::abs(head->data - item) < EPSILON)
    {
        Tools::Node<double>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Tools::Node<double>* traverse = head;
    Tools::Node<double>* prev = head;


    // FIXME: remove node at any place while keeping the tail pointing to the last node
}
