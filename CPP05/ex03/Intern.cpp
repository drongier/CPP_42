/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:56:22 by drongier          #+#    #+#             */
/*   Updated: 2025/06/09 11:56:23 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern::~Intern() {}
Intern& Intern::operator=(const Intern&) { return *this; }

AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[])(std::string const &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern couldn't find form: " << name << std::endl;
    return NULL;
}
