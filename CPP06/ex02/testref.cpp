#include <iostream>

int main() {
    int a = 42;
    int& ref = a;
    ref = 99;
    a = 28;

    std::cout << ref << std::endl;
}
