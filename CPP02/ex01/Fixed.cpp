/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:11:35 by drongier          #+#    #+#             */
/*   Updated: 2025/03/10 19:11:36 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits() const {
    return this->_value;
}


void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}


float Fixed::toFloat() const {
    return (float)this->_value / (1 << _fractionalBits);
}


int Fixed::toInt() const {
    return this->_value >> _fractionalBits;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}