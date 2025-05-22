#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat high("HighRank", 1);
		Bureaucrat mid("MidRank", 50);
		Bureaucrat low("LowRank", 150);

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n\033[1;36m--- SIGNING FORMS ---\033[0m\n";
		low.signForm(shrub);      // OK (145 to sign)
		mid.signForm(robot);      // OK (72 to sign)
		high.signForm(pardon);    // OK (25 to sign)

		std::cout << "\n\033[1;36m--- EXECUTING FORMS ---\033[0m\n";

		// Too low to executeForm
		low.executeForm(shrub);   // ERROR (137 required)
		mid.executeForm(robot);   // OK or fail randomly
		high.executeForm(pardon); // OK

		// Test: try to executeForm an unsigned form
		ShrubberyCreationForm unsignedForm("forest");
		high.executeForm(unsignedForm); // ERROR

	} catch (std::exception& e) {
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	return 0;
}
