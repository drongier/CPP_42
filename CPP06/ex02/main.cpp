#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing type identification ===" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        
        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "  identify(Base*): ";
        identify_ptr(obj);
        std::cout << "  identify(Base&): ";
        identify_ref(*obj);
        std::cout << std::endl;
        
        delete obj;
    }
    
    // std::cout << "\n=== Testing with unsupported type D ===" << std::endl;
    // Base* objD = new D();
    
    // std::cout << "Test with D:" << std::endl;
    // std::cout << "  identify(Base*): ";
    // identify_ptr(objD);
    // std::cout << "  identify(Base&): ";
    // identify_ref(*objD);
    // std::cout << std::endl;
    
    // delete objD;
    
    return 0;
}