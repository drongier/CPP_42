#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Fonctions de test pour les exemples
template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template<typename T>
void doubleValue(T& element) {
    element *= 2;
}

void toUpperCase(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

#endif