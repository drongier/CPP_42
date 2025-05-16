#include "AAnimal.hpp"

AAnimal::AAnimal() : type( "AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& src) : type(src.type) {

	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
	if (this != &src) {
        type = src.type;
	}
	std::cout << "AAnimal assignement operator" << std::endl;	
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;	
}

// ---------------------------------------------------------------------- //

void	AAnimal::makeSound( void ) const {
	std::cout << " No sound ! " << std::endl;
}

std::string		AAnimal::getType( void ) const { return type; }