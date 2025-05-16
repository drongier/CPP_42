#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal() { 
	type = "Cat";
	std::cout << "Cat constructor called.. Miaou !" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal( src ) {
	std::cout << "Cat copy constructor called.. Miaou !" << std::endl;
}

Cat& Cat::operator=( const Cat& src) {
	if (this != &src)
		type = src.type;
	std::cout << "Cat assignment operator used.. Miaou !" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called.. Miaou !" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << " Miaou Miaou ! " << std::endl;
}