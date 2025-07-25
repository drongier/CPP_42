/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:55:38 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 11:55:39 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class  AForm
{
    protected:
    void checkExecutability(Bureaucrat const & executor) const;
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public :

    //OCF
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    virtual ~AForm();

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

    virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif