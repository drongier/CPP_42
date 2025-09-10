#include "MutantStack.hpp"

int main()
{
    std::cout << "=== MUTANTSTACK ITERATOR TESTS ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    
    std::cout << "\nStack contents: [1, 2, 3, 4, 5] (bottom to top)" << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    // 1. TEST: iterator (begin/end)
    std::cout << "\n1. Testing iterator (begin/end):" << std::endl;
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 2. TEST: const_iterator (begin/end) with const object
    std::cout << "\n2. Testing const_iterator (begin/end):" << std::endl;
    const MutantStack<int> const_mstack = mstack;
    std::cout << "Const forward iteration: ";
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 3. TEST: reverse_iterator (rbegin/rend)
    std::cout << "\n3. Testing reverse_iterator (rbegin/rend):" << std::endl;
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 4. TEST: const_reverse_iterator (rbegin/rend)
    std::cout << "\n4. Testing const_reverse_iterator (rbegin/rend):" << std::endl;
    std::cout << "Const reverse iteration: ";
    for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}