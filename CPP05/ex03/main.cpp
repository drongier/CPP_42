/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:57:55 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 16:47:06 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║             INTERN TESTS                  ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat intern_bureaucrat("InternBureaucrat", 150);
    Intern intern;

    std::cout << "\n\033[1;32m═══ TEST 1: VALID SHRUBBERY CREATION FORM ═══\033[0m\n";
    try {
        AForm* shrubForm = intern.makeForm("shrubbery creation", "backyard");
        if (shrubForm) {
            std::cout << *shrubForm << std::endl;
            manager.signForm(*shrubForm);
            manager.executeForm(*shrubForm);
            
            delete shrubForm;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 2: VALID ROBOTOMY REQUEST FORM ═══\033[0m\n";
    try {
        AForm* robotForm = intern.makeForm("robotomy request", "Bender");
        if (robotForm) {
            std::cout << *robotForm << std::endl;
            
            manager.signForm(*robotForm);
            president.executeForm(*robotForm);
            
            delete robotForm;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 3: VALID PRESIDENTIAL PARDON FORM ═══\033[0m\n";
    try {
        AForm* pardonForm = intern.makeForm("presidential pardon", "Arthur_Dent");
        if (pardonForm) {
            std::cout << *pardonForm << std::endl;
            
            president.signForm(*pardonForm);
            president.executeForm(*pardonForm);
            
            delete pardonForm;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 4: INVALID FORM NAME ═══\033[0m\n";
    try {
        AForm* invalidForm = intern.makeForm("invalid form", "Target");
        if (invalidForm) {
            std::cout << *invalidForm << std::endl;
            delete invalidForm;
        } else {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 5: EMPTY FORM NAME ═══\033[0m\n";
    try {
        AForm* emptyForm = intern.makeForm("", "Target");
        if (emptyForm) {
            std::cout << *emptyForm << std::endl;
            delete emptyForm;
        } else {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 6: CASE SENSITIVITY ═══\033[0m\n";
    try {
        AForm* upperForm = intern.makeForm("ROBOTOMY REQUEST", "R2D2");
        if (upperForm) {
            std::cout << "Uppercase worked: " << *upperForm << std::endl;
            delete upperForm;
        } else {
            std::cout << "Uppercase form creation failed" << std::endl;
        }

        AForm* mixedForm = intern.makeForm("Shrubbery Creation", "garden");
        if (mixedForm) {
            std::cout << "Mixed case worked: " << *mixedForm << std::endl;
            delete mixedForm;
        } else {
            std::cout << "Mixed case form creation failed" << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 7: MULTIPLE FORMS CREATION ═══\033[0m\n";
    try {
        std::cout << "Creating multiple forms with same intern...\n";
        
        AForm* form1 = intern.makeForm("shrubbery creation", "park1");
        AForm* form2 = intern.makeForm("robotomy request", "Wall-E");
        AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");
        
        if (form1 && form2 && form3) {
            std::cout << "All forms created successfully:\n";
            std::cout << *form1 << std::endl;
            std::cout << *form2 << std::endl;
            std::cout << *form3 << std::endl;
            
            delete form1;
            delete form2;
            delete form3;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 8: FORM WITH SPECIAL CHARACTERS ═══\033[0m\n";
    try {
        AForm* specialForm = intern.makeForm("shrubbery creation", "garden_with_spaces and-dashes");
        if (specialForm) {
            std::cout << *specialForm << std::endl;
            delete specialForm;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;36m═══ TEST 9: WORKFLOW WITH DIFFERENT BUREAUCRATS ═══\033[0m\n";
    try {
        AForm* workflowForm = intern.makeForm("robotomy request", "TestRobot");
        if (workflowForm) {
            std::cout << "Form created: " << *workflowForm << std::endl;
            
            std::cout << "\nTrying with intern bureaucrat (grade 150):\n";
            try {
                intern_bureaucrat.signForm(*workflowForm);
            } catch (std::exception& e) {
                std::cerr << "Signing failed: " << e.what() << std::endl;
            }
            
            std::cout << "\nTrying with manager (grade 50):\n";
            manager.signForm(*workflowForm);
            manager.executeForm(*workflowForm);
            
            delete workflowForm;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║           INTERN TESTS COMPLETED          ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    return 0;
}