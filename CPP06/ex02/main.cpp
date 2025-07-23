#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing type identification ===" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        
        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "  identify(Base*): ";
        identify(obj);
        std::cout << "  identify(Base&): ";
        identify(*obj);
        std::cout << std::endl;
        
        delete obj;
    }
    
    return 0;
}