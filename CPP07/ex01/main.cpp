#include "Iter.hpp"

int main() {
    std::cout << "=== Test 1 ===" << std::endl;
    
    int intArray[5] = {1, 2, 3, 4, 5};
    
    std::cout << "Original non-const array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(intArray, 5, doubleValue<int>);
    std::cout << "After double: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl << std::endl;
    
    std::cout << "After +28: ";
    iter(intArray, 5, plus28<int>);
    std::cout << std::endl << std::endl;

    
    return 0;
}