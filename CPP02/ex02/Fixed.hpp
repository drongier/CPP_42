/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:08 by drongier          #+#    #+#             */
/*   Updated: 2025/03/12 13:57:16 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int 				_value; 
    static const int	_fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

	bool operator >(Fixed const &other) const;
	bool operator <(Fixed const &other) const;
	bool operator >=(Fixed const &other) const;
	bool operator <=(Fixed const &other) const;
	bool operator ==(Fixed const &other) const;	
	bool operator !=(Fixed const &other) const;
	
	Fixed operator +(Fixed const &other) const;
	Fixed operator -(Fixed const &other) const;
	Fixed operator *(Fixed const &other) const;
	Fixed operator /(Fixed const &other) const;
	
	Fixed &operator ++();
	Fixed operator ++(int);
	Fixed &operator --();
	Fixed operator --(int);
	
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif