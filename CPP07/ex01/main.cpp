#include "Iter.hpp"

int main() {
    std::cout << "=== Test 1: Integers (non-const and const) ===" << std::endl;
    
    // Test with non-const array
    int intArray[5] = {1, 2, 3, 4, 5};
    
    std::cout << "Original non-const array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    
    // Modification possible (non-const)
    iter(intArray, 5, doubleValue<int>);
    std::cout << "After modification: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    
    // Test with const array
    const int constIntArray[] = {10, 20, 30, 40};
    size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const array: ";
    iter(constIntArray, constIntSize, printElement<int>);
    std::cout << std::endl << std::endl;
    
    std::cout << "=== Test 2: Strings (non-const and const) ===" << std::endl;
    
    // Test with non-const array
    std::string stringArray[] = {"Hello", "World", "CPP"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Non-const array: ";
    iter(stringArray, stringSize, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << "String lengths: ";
    iter(stringArray, stringSize, printStringLength);
    std::cout << std::endl;
    
    // Test with const array
    const std::string constStringArray[] = {"Coucou", "String", "Test"};
    size_t constStringSize = sizeof(constStringArray) / sizeof(constStringArray[0]);
    
    std::cout << "Const array: ";
    iter(constStringArray, constStringSize, printElement<std::string>);

	std::cout << "String lengths: ";
    iter(constStringArray, constStringSize, printStringLength);
    std::cout << std::endl;
	std::cout << std::endl;
    
    return 0;
}