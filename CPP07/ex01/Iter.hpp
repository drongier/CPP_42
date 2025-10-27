#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template<typename T>
void doubleValue(T& element) {
    element *= 2;
}

template<typename T>
void plus28(T& element) {
    element = element + 28;
    std::cout << element << " ";
}

#endif