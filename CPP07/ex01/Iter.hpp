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

template<typename T, typename F>
void iter(const T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Template pour doubler une valeur (nécessite un référence non-const)
template<typename T>
void doubleValue(T& element) {
    element *= 2;
}

// Fonction spécialisée pour convertir en majuscules
void toUpperCase(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

// Fonction pour afficher la longueur des strings (const)
void printStringLength(const std::string& str) {
    std::cout << "[" << str.length() << "]";
}

#endif