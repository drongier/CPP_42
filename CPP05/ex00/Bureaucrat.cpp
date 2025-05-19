#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : { 
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src) {
        this->_src = src._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}