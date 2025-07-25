/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:56:11 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 11:56:12 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
    Bureaucrat& operator=( const Bureaucrat& other );
    ~Bureaucrat();

	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Méthodes de modification de grade
	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form);
	void executeForm(AForm const & form) const;

	// Exceptions personnalisées
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif