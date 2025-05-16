#include "AAnimal.hpp"
#include "Dog.hpp"

Dog::Dog() : AAnimal() { 
	type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& src ) : AAnimal( src ) {
	std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src) {
		type = src.type;

		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);

		std::cout << "Dog assignment operator used" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

// ------------------------------------------------------------- //


void	Dog::makeSound( void ) const {
	std::cout << " Ouaf ouaf ! " << std::endl;
}

void Dog::setBrainIdea(size_t index, const std::string& idea) {
	if (_brain)
		_brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(size_t index) const {
	if (_brain)
		return _brain->getIdea(index);
	return "";
}