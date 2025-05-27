#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing type identification ===" << std::endl;
    
    // Test avec plusieurs générations aléatoires
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
    
    // Test avec des objets connus
    std::cout << "=== Testing with known objects ===" << std::endl;
    
    A* a = new A();
    B* b = new B();
    C* c = new C();
    
    std::cout << "Object A:" << std::endl;
    identify(a);
    identify(*a);
    
    std::cout << "Object B:" << std::endl;
    identify(b);
    identify(*b);
    
    std::cout << "Object C:" << std::endl;
    identify(c);
    identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}