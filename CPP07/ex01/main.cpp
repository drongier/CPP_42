#include "Iter.hpp"
#include <string>

int main() {
    std::cout << "=== Test avec des entiers ===" << std::endl;
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Tableau original: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    // Doubler chaque valeur
    iter(intArray, intSize, doubleValue<int>);
    std::cout << "Après doublement: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl << std::endl;
    
    std::cout << "=== Test avec des strings ===" << std::endl;
    
    std::string stringArray[] = {"Hello", "World", "Templates", "Rock"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Tableau de strings: ";
    iter(stringArray, stringSize, printElement<std::string>);
    std::cout << std::endl << std::endl;
    
    std::cout << "=== Test avec des chars ===" << std::endl;
    
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Tableau original: ";
    iter(charArray, charSize, printElement<char>);
    std::cout << std::endl;
    
    // Convertir en majuscules
    iter(charArray, charSize, toUpperCase);
    std::cout << "En majuscules: ";
    iter(charArray, charSize, printElement<char>);
    std::cout << std::endl << std::endl;
    
    std::cout << "=== Test avec des doubles ===" << std::endl;
    
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Tableau original: ";
    iter(doubleArray, doubleSize, printElement<double>);
    std::cout << std::endl;
    
    iter(doubleArray, doubleSize, doubleValue<double>);
    std::cout << "Après doublement: ";
    iter(doubleArray, doubleSize, printElement<double>);
    std::cout << std::endl;
    
    return 0;
}