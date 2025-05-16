#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type( "WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src) : type(src.type) {

	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	if (this != &src) {
        type = src.type;
	}
	std::cout << "WrongAnimal assignement operator" << std::endl;	
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;	
}

// --------------------------------------- //

void	WrongAnimal::makeSound( void ) const {
	std::cout << " No sound ! " << std::endl;
}

std::string		WrongAnimal::getType( void ) const { return type; }