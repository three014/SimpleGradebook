#pragma once

#ifndef STUDENT_LINKED_LIST_H
#define STUDENT_LINKED_LIST_H

#include "LinkedList.hpp"

namespace Gradebook
{
    class StudentLinkedList :
        public Tools::LinkedList<double>
    {
    public:
        StudentLinkedList() : LinkedList() {}
        void remove(double);
    };
}


#endif