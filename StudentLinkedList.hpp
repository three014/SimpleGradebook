#pragma once

#ifndef STUDENT_LINKED_LIST_H
#define STUDENT_LINKED_LIST_H

#include "LinkedList.hpp"

namespace Gradebook
{
    class StudentLinkedList :
        public Tools::LinkedList<double>
    {
    protected:
        double const EPSILON = 0.00001;
    public:
        StudentLinkedList() : LinkedList() {}
        void remove(double);
    };
}


#endif
