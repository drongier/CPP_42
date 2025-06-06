#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

Form::~Form() {
		std::cout << "Form destructor called" << std::endl;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low";
}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form \"" << form.getName()
	   << "\", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}