#include "Serializer.hpp"
#include <iostream>

int main() {
    std::cout << "=== Serializer Test ===" << std::endl;

    Data originalData;
    originalData.id = 42;
    originalData.name = "Test";
    originalData.value = 3.14;

    Data* originalPtr = &originalData;
    
    std::cout << "\nOriginal pointer: " << originalPtr << std::endl;
    std::cout << "Original data: id=" << originalPtr->id 
              << ", name=" << originalPtr->name 
              << ", value=" << originalPtr->value << std::endl;

    // Sérialiser
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;

    // Désérialiser
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "\nDeserialized pointer: " << deserializedPtr << std::endl;

    // Vérification principale
    if (originalPtr == deserializedPtr) {
        std::cout << "Deserialized data: id=" << deserializedPtr->id 
                  << ", name=" << deserializedPtr->name 
                  << ", value=" << deserializedPtr->value << std::endl;
        std::cout << "\n✓ SUCCESS: Pointers are equal!" << std::endl;
    } else {
        std::cout << "\n✗ FAILURE: Pointers are different!" << std::endl;
    }
    
    return 0;
}