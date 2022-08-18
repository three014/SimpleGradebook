// Gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "hashmap.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    // based on a guide I read, they used a dummy node, but I wonder if I don't need that??
    Tools::HashMap<std::string, std::string>* test = new Tools::HashMap<std::string, std::string>("-1", "-1");

    test->insert_node("English", "Good");
    std::cout << "Just added a node to this hashmap and nothing has broken yet :D\n";

    test->delete_node("English");
    std::cout << "Now I deleted a node, if we're here then we should be fine?\n";

    delete test;
}