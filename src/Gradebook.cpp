// Gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "HashMap.hpp"
#include "StudentLinkedList.hpp"

int main(int argc, char** argv)
{
    std::string dummy_str = "";
    int dummy_int = -1;


    /* Making sure the program starts at all */
    std::cout << "Hello World!\n\n";

    /* First Test: Creating a hashmap with the correct dummy input */
    Tools::HashMap<std::string, int>* test = 
            new Tools::HashMap<std::string, int>(dummy_str, dummy_int);

    test->insert_node("English", 2);
    std::cout << "Added Node \"English\" with value 2" << "\n";
    std::cout << "Retrieving node value: " << test->get_value("English") << "\n";
    std::cout << "Retrieving value for node that doesn't exist: " << test->get_value("Math") << "\n";
    std::cout << "Deleting node returns its value: " << test->delete_node("English") << "\n";

    test->insert_node("Mathematics", 5);
    std::cout << "Added Node \"Mathematics\" with value 5" << "\n";
    std::cout << "Retrieving node value: " << test->get_value("Mathematics") << "\n";
    test->insert_node("History of Jazz", 7);
    std::cout << "Added Node \"History of Jazz\" with value 7" << "\n";
    std::cout << "Retrieving node value: " << test->get_value("History of Jazz") << "\n";
    test->insert_node("Computer Programming I", 1);
    std::cout << "Added Node \"Computer Programming\" with value 1" << "\n";


    delete test;


    std::cout << "\nNow I'm going to test out my Linked List\n";
    
    Gradebook::StudentLinkedList dummy;
    Gradebook::StudentLinkedList* test_grades = new Gradebook::StudentLinkedList();
    test_grades->push(94.8);

    Tools::HashMap<std::string, Gradebook::StudentLinkedList*>* student_gradebook = 
            new Tools::HashMap<std::string, Gradebook::StudentLinkedList*>(dummy_str, &dummy);
    student_gradebook->insert_node("English", test_grades);
    Gradebook::StudentLinkedList* read_grades = student_gradebook->get_value("English");
    std::cout << read_grades->pop() << "\n";
    delete student_gradebook;
    
}

