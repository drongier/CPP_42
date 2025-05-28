#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;  // Si égaux, retourne b (le second)
}

template<typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;  // Si égaux, retourne b (le second)
}

#endif