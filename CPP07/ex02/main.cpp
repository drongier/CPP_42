// main.cpp
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Constructor empty array ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size empty array : " << emptyArray.getSize() << std::endl;
    
    std::cout << "\n=== Constructor array with size(x) ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Size of array : " << intArray.getSize() << std::endl;
    
    // Initialisation des valeurs
    for (unsigned int i = 0; i < intArray.getSize(); i++) {
        intArray[i] = i * 10;
    }
    
    std::cout << "Valeurs: ";
    for (unsigned int i = 0; i < intArray.getSize(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Test constructeur de copie ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Taille de la copie: " << copyArray.getSize() << std::endl;
    
    // Modifier l'original pour tester la deep copy
    intArray[0] = 999;
    std::cout << "Original[0] après modification: " << intArray[0] << std::endl;
    std::cout << "Copie[0] (doit rester inchangé): " << copyArray[0] << std::endl;
    
    std::cout << "\n=== Test opérateur d'assignation ===" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Taille après assignation: " << assignedArray.getSize() << std::endl;
    
    std::cout << "\n=== Test avec des strings ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Templates";
    
    for (unsigned int i = 0; i < stringArray.getSize(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Test des exceptions ===" << std::endl;
    try {
        std::cout << "Tentative d'accès hors limites..." << std::endl;
        std::cout << intArray[100] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception attrapée pour accès hors limites" << std::endl;
    }
    
    try {
        std::cout << "Tentative d'accès hors limites sur tableau vide..." << std::endl;
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception attrapée pour tableau vide" << std::endl;
    }
    
    return 0;
}