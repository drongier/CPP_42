#include "Animal.hpp"

Animal::Animal() : type( "Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& src) : type(src.type) {

	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
	if (this != &src) {
        type = src.type;
	}
	std::cout << "Animal assignement operator" << std::endl;	
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;	
}

// --------------------------------------- //

void	Animal::makeSound( void ) const {
	std::cout << " No sound ! " << std::endl;
}

std::string		Animal::getType( void ) const { return type; }