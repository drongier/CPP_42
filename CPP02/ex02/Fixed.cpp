/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:11:35 by drongier          #+#    #+#             */
/*   Updated: 2025/03/12 14:27:25 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed(void) {
    //std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return;
}

Fixed::Fixed(const int x) {
    //std::cout << "Int constructor called" << std::endl;
	this->_value = x << this->_fractionalBits;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
    //std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) : _value(other._value) {
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator =(Fixed const &src)
{
	//std::cout << "Copy assignement operator called." << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}


Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

// COMPARAISON

bool	Fixed::operator >(Fixed const &src) const
{
	return this->_value > src._value;
}

bool	Fixed::operator <(Fixed const &src) const
{
	return this->_value < src._value;
}

bool	Fixed::operator >=(Fixed const &src) const
{
	return this->_value >= src._value;
}

bool	Fixed::operator <=(Fixed const &src) const
{
	return this->_value <= src._value;
}

bool	Fixed::operator ==(Fixed const &src) const
{
	return this->_value == src._value;
}

bool	Fixed::operator !=(Fixed const &src) const
{
	return this->_value != src._value;
}

// ARITH

Fixed	Fixed::operator+(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits(this->_value + src._value);
	return result;
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits(this->_value - src._value);
	return result;
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits((this->_value * src._value) >> this->_fractionalBits);
	return result;
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits((this->_value << this->_fractionalBits) / src._value);
	return result;
}

// INCRE / DECREM 

Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	temp(*this);

	this->_value;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	temp(*this);
	
	this->_value--;
	return temp;
}

// FUNCTIONS

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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

// OVERLOAD

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}