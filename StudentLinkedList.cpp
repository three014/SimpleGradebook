#include <iostream>
#include "StudentLinkedList.hpp"

void Gradebook::StudentLinkedList::remove(double item)
{
    if (head == nullptr)
    {
        return;
    }

    Tools::Node<double>* traverse = head;
    Tools::Node<double>* prev = nullptr;
    double const EPSILON = 0.00001;


    // FIXME: remove node at any place while keeping the tail pointing to the last node
    if (std::abs(traverse->data - item) < EPSILON)
    {
        head = traverse->next;
        delete traverse;
    }
    else
    {
        while (traverse != nullptr)
        {
            if (std::abs(traverse->data - item) < EPSILON)
            {
                prev->next = traverse->next;
                delete traverse;
                break;
            }

            prev = traverse;
            traverse = traverse->next;
        }

        if (prev->next == nullptr)
        {
            tail = prev;
        }
    }
}
