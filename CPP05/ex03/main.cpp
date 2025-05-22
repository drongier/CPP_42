#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form)
        std::cout << *form << std::endl;

    AForm* badForm = intern.makeForm("invalid form", "Target");

    delete form;
    delete badForm;

    return 0;
}
