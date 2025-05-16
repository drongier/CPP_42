#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal() { 
	type = "Dog";
	std::cout << "Dog constructor called.. Ouaf !" << std::endl;
}

Dog::Dog( const Dog& src ) : Animal( src ) {
	std::cout << "Dog copy constructor called.. Ouaf !" << std::endl;
}

Dog& Dog::operator=( const Dog& src) {
	if (this != &src)
		type = src.type;
	std::cout << "Dog assignment operator used.. Ouaf !" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called.. Ouaf !" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << " Ouaf ouaf ! " << std::endl;
}