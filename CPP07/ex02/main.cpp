// main.cpp
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {

    //Empty array
    std::cout << "=== Constructor empty array ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size empty array : " << emptyArray.getSize() << std::endl;
    

    //array with size(x)
    std::cout << "\n=== Constructor array with size(x) ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Size of array : " << intArray.getSize() << std::endl;

    for (unsigned int i = 0; i < intArray.getSize(); i++) {
        intArray[i] = i * 10;
    }
    std::cout << "Values: " << intArray << std::endl;
    
    //Constructor copy
    std::cout << "\n=== Test copy constructor ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Copy size: " << copyArray.getSize() << std::endl;

    intArray[0] = 28;
    std::cout << "Original[0] after change: " << intArray[0] << std::endl;
    std::cout << "Copie[0] : " << copyArray[0] << std::endl;


    std::cout << "\n=== Test opérateur d'assignation ===" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "assignedArray = intArray" << std::endl;
    std::cout << "Size after assignation : " << assignedArray.getSize() << std::endl;
    std::cout << "AssignedArray[0] = " << assignedArray[0] << std::endl;
    
    std::cout << "\n=== Test with strings ===" << std::endl;
    Array<std::string> stringArray(2);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    
    for (unsigned int i = 0; i < stringArray.getSize(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Test exceptions ===" << std::endl;
    try {
        std::cout << "Try to acces out of range (intArray[6]) : " << std::endl;
        std::cout << intArray[6] << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try to acces empty array" << std::endl;
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}