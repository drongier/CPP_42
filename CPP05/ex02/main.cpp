/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:50:03 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 14:31:19 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║           FORM EXECUTION TESTS            ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    Bureaucrat president("President", 1);
    Bureaucrat director("Director", 25);
    Bureaucrat manager("Manager", 50);
    Bureaucrat supervisor("Supervisor", 72);
    Bureaucrat clerk("Clerk", 100);
    Bureaucrat intern("Intern", 150);

    std::cout << "\n\033[1;32m═══ TEST 1: SUCCESSFUL FORM SIGNING & EXECUTION ═══\033[0m\n";
    try {
        ShrubberyCreationForm shrub("home_garden");
        std::cout << shrub << std::endl;
        
        clerk.signForm(shrub);
        manager.executeForm(shrub);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;36m═══ TEST 2: ROBOTOMY REQUEST - MULTIPLE ATTEMPTS ═══\033[0m\n";
    try {
        RobotomyRequestForm robot("R2D2");
        std::cout << robot << std::endl;
        
        supervisor.signForm(robot);
        
        for (int i = 1; i <= 5; i++) {
            std::cout << "\nAttempt " << i << ":\n";
            usleep(200000);
            president.executeForm(robot);
        }
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 3: PRESIDENTIAL PARDON - SUCCESS ═══\033[0m\n";
    try {
        PresidentialPardonForm pardon("Arthur_Dent");
        std::cout << pardon << std::endl;
        
        director.signForm(pardon);
        president.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 4: EXECUTION WITHOUT SIGNATURE ═══\033[0m\n";
    try {
        ShrubberyCreationForm unsignedForm("unsigned_garden");
        std::cout << unsignedForm << std::endl;
        
        president.executeForm(unsignedForm);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 5: INSUFFICIENT GRADE FOR EXECUTION ═══\033[0m\n";
    try {
        ShrubberyCreationForm shrub2("office_garden");
        std::cout << shrub2 << std::endl;
        
        intern.signForm(shrub2); 
        intern.executeForm(shrub2);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 6: INSUFFICIENT GRADE FOR SIGNING ═══\033[0m\n";
    try {
        RobotomyRequestForm robot2("C3PO");
        std::cout << robot2 << std::endl;
        
        intern.signForm(robot2);   
        president.executeForm(robot2);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 7: PRESIDENTIAL PARDON - INSUFFICIENT EXECUTION GRADE ═══\033[0m\n";
    try {
        PresidentialPardonForm pardon2("Ford_Prefect");
        std::cout << pardon2 << std::endl;
        
        president.signForm(pardon2); 
        director.executeForm(pardon2);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 8: MULTIPLE FORMS WITH SAME BUREAUCRAT ═══\033[0m\n";
    try {
        ShrubberyCreationForm shrub4("park");
        RobotomyRequestForm robot3("Wall-E");
        PresidentialPardonForm pardon3("Zaphod_Beeblebrox");
        
        // President can sign and execute all forms
        president.signForm(shrub4);
        president.signForm(robot3);
        president.signForm(pardon3);
        
        president.executeForm(shrub4);
        president.executeForm(robot3);
        president.executeForm(pardon3);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║        FORM EXECUTION TESTS COMPLETED     ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    return 0;
}