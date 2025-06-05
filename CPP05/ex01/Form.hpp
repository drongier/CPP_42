#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class  Form
{
    private :
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public :

    //OCF
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& src);
    Form& operator=(const Form& src);
    ~Form();

    // Exceptions 
    class GradeTooHighException : public std::exception {
        public :
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public :
            const char* what() const throw();
    };

    // Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

    // Fonction pour signer
	void beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif