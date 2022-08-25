// Gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HashMap.hpp"
#include "StudentLinkedList.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    // based on a guide I read, they used a dummy node, but I wonder if I don't need that??
    Tools::HashMap<std::string, int>* test = new Tools::HashMap<std::string, int>("", -1);

    test->insert_node("English", 2);
    std::cout << "Just added a node to this hashmap and nothing has broken yet :D\n";
    std::cout << "Node value: " << test->get_value("English") << "\n";
    std::cout << test->get_value("Math") << "\n\n";

    std::cout << test->delete_node("English") << "\n";
    std::cout << "Now I deleted a node, if we're here then we should be fine?\n";

    delete test;


    std::cout << "\nNow I'm going to test out my Linked List\n";
    
    Gradebook::StudentLinkedList dummy;
    Gradebook::StudentLinkedList* test_grades = new Gradebook::StudentLinkedList();
    test_grades->push(94.8);

    Tools::HashMap<std::string, Gradebook::StudentLinkedList*>* student_gradebook = new Tools::HashMap<std::string, Gradebook::StudentLinkedList*>("", &dummy);
    student_gradebook->insert_node("English", test_grades);
    delete student_gradebook;
    
}
