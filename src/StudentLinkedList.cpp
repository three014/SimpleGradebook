#include <iostream>
#include "StudentLinkedList.hpp"

void Gradebook::StudentLinkedList::remove(double item)
{
    if (head != nullptr && std::abs(head->data - item) < EPSILON)
    {
        Tools::Node<double>* temp = head;
        head = head->next;
        delete temp;
        list_size--;
        return;
    }

    Tools::Node<double>* traverse = head;
    Tools::Node<double>* prev = head;


    // FIXME: remove node at any place while keeping the tail pointing to the last node
    while (traverse != tail && traverse != nullptr)
    {
        if (std::abs(traverse->data - item) < EPSILON)
        {
            prev->next = traverse->next;
            delete traverse;
            list_size--;
            return;
        }
        prev = traverse;
        traverse = traverse->next;
    }
    if (traverse == tail && std::abs(traverse->data - item) < EPSILON)
    {
        tail = prev;
        delete traverse;
        list_size--;
        return;
    }
}
