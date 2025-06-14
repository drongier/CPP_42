/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:55:59 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 11:56:00 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) { 
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string & name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src) {
        _grade = src._grade;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//----------------------------------------------------------------------------------//

// Getters
const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

// Méthodes
void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

// Surcharge <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm& form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                 << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn’t execute " << form.getName()
		          << " because " << e.what() << std::endl;
	}
}
