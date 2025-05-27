#include "Serializer.hpp"
#include <iostream>

int main() {
    // Créer un objet Data
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test";
    originalData.value = 3.14;

    Data* originalPtr = &originalData;
    
    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Original data: id=" << originalPtr->id 
              << ", name=" << originalPtr->name 
              << ", value=" << originalPtr->value << std::endl;

    // Sérialiser le pointeur
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;

    // Désérialiser
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    // Vérifier que les pointeurs sont identiques
    if (originalPtr == deserializedPtr) {
        std::cout << "✓ Pointers are equal!" << std::endl;
        std::cout << "Deserialized data: id=" << deserializedPtr->id 
                  << ", name=" << deserializedPtr->name 
                  << ", value=" << deserializedPtr->value << std::endl;
    } else {
        std::cout << "✗ Pointers are different!" << std::endl;
    }

    return 0;
}