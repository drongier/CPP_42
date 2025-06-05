/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:37:59 by drongier          #+#    #+#             */
/*   Updated: 2025/06/05 13:09:59 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat {
	
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

	// Méthodes
	void incrementGrade();
	void decrementGrade(); 

};

// Exceptions
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif