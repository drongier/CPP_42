#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
		_signed = src._signed; // seuls attributs modifiables
	return *this;
}

AForm::~AForm() {}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm: Grade too low";
}

// Getters
const std::string& AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

// Fonction pour signer
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm \"" << Aform.getName()
	   << "\", signed: " << (Aform.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << Aform.getGradeToSign()
	   << ", grade to execute: " << Aform.getGradeToExecute();
	return os;
}

void AForm::checkExecutability(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed and cannot be executed.");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
}