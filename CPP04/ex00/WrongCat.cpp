#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& src) : WrongAnimal(src) {

	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	if (this != &src) {
        type = src.type;
	}
	std::cout << "WrongCat assignement operator" << std::endl;	
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;	
}

// --------------------------------------- //

void	WrongCat::makeSound( void ) const {
	std::cout << " Miaou ! " << std::endl;
}

std::string		WrongCat::getType( void ) const { return type; }