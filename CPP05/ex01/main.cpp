#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	try {
		Bureaucrat bob("Bob", 28);
		Form taxForm("TaxForm2025", 30, 25);

		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
