#include "Array.hpp"

template <class T>
Array<T>::Array(): _size(0), _array(NULL) {}

template <class T>
Array<T>::Array(unsigned int n) : _size(n), _array(_size > 0 ? new T[_size] : NULL) {}

template <class T>
Array<T>::Array(const Array<T>& src) : _size(src._size), _array(new T[_size]) {
	for (unsigned int i = 0; i < _size; ++i) {
		_array[i] = src._array[i];
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
    if (this != &src) {
        _size = src._size;
		delete[] _array;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			_array[i] = src._array[i];
		}
	}
	return (*this);
}

template <class T>
Array<T>::~Array() { delete[] _array; }

template <class T>
unsigned int Array<T>::getSize(void) const {return (_size);}

template <class T>
T& Array<T>::operator[]( const unsigned int i ) {
	if (i >= this->getSize())
		throw OutOfBoundException();
	else
		return (_array[i]);
}

template <class T>
const T& Array<T>::operator[]( const unsigned int i ) const {
	if (i >= this->getSize())
		throw OutOfBoundException();
	else
		return (_array[i]);
}

template<typename T>
const char    *Array<T>::OutOfBoundException::what(void) const throw() {
    return ("error: index out");
}

template <class T>
std::ostream& operator<<( std::ostream& os, const Array<T>& arr ) {
	if (!arr.getSize())
		os << "{ }";
	else {
		os << "{ ";
		for (unsigned int i = 0; i < arr.getSize() - 1; ++i) {
			os << arr[i] << " , ";
		}
		os << arr[arr.getSize() - 1] << " }";
	}
	return (os);
}