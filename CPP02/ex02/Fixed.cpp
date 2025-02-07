#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructeur par défaut
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur prenant un entier
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Constructeur prenant un flottant
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

// Constructeur de copie
Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Opérateur d'affectation par copie
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Retourne la valeur brute
int Fixed::getRawBits() const {
    return this->_value;
}

// Définit la valeur brute
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Convertit en flottant
float Fixed::toFloat() const {
    return (float)this->_value / (1 << _fractionalBits);
}

// Convertit en entier
int Fixed::toInt() const {
    return this->_value >> _fractionalBits;
}

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}