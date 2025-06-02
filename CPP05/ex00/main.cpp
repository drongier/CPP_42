/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:38:03 by drongier          #+#    #+#             */
/*   Updated: 2025/06/02 12:38:04 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Jean", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade(); // passe à 1
		std::cout << b1 << std::endl;

		b1.incrementGrade(); // Exception GradeTooHigh
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	try {
		Bureaucrat b2("Paul", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade(); // passe à 150
		std::cout << b2 << std::endl;

		b2.decrementGrade(); // Exception GradeTooLow
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
