/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:55:42 by drongier          #+#    #+#             */
/*   Updated: 2025/10/27 12:55:43 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<class T>
class Array {
private:
	unsigned int	_size;
	T*				_array;

	class OutOfBoundException: public std::exception {
	public:
		const char *what () const throw();
	};

public:
	Array();
	Array(unsigned int n);
	Array( const Array& src);
	Array& operator=(const Array& src);
	~Array();

	T&			operator[](const unsigned int i);
	const T&	operator[](const unsigned int i) const;
	unsigned int	getSize(void) const;
};

template <class T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& arr );

#include "Array.tpp"

#endif