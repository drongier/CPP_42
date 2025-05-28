#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // Constructeur par défaut : tableau vide
    Array() : _array(NULL), _size(0) {}
    
    // Constructeur avec taille : n éléments initialisés par défaut
    Array(unsigned int n) : _array(NULL), _size(n) {
        if (n > 0) {
            _array = new T[n]();  // () pour initialisation par défaut
        }
    }
    
    // Constructeur de copie
    Array(const Array& src) : _array(NULL), _size(0) {
        *this = src;
    }
    
    // Destructeur
    ~Array() {
        delete[] _array;
    }
    
    // Opérateur d'assignation
    Array& operator=(const Array& src) {
        if (this != &src) {
            delete[] _array;
            _size = src._size;
            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = src._array[i];
                }
            } else {
                _array = NULL;
            }
        }
        return *this;
    }
    
    // Opérateur de subscript (lecture/écriture)
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::exception();
        }
        return _array[index];
    }
    
    // Opérateur de subscript (lecture seule)
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::exception();
        }
        return _array[index];
    }
    
    // Fonction size
    unsigned int size() const {
        return _size;
    }
};

#endif