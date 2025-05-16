#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat() : AAnimal() { 
	type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& src ) : AAnimal( src ) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat& Cat::operator=( const Cat& src) {
	if (this != &src) {
		type = src.type;

		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
		std::cout << "Cat assignment operator used" << std::endl;

	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

// ------------------------------------------------------------- //

void	Cat::makeSound( void ) const {
	std::cout << " Miaou Miaou ! " << std::endl;
}

void Cat::setBrainIdea(size_t index, const std::string& idea) {
	if (_brain)
		_brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(size_t index) const {
	if (_brain)
		return _brain->getIdea(index);
	return "";
}