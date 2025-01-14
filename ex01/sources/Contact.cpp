/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:20:04 by drongier          #+#    #+#             */
/*   Updated: 2025/01/14 16:50:08 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "../includes/Contact.hpp"

void	Contact::addContact(size_t size)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
	std::cout << "Contact saved ! " << std::endl;
	this->index = size;
	
    setFirstName(firstName);
    setLastName(lastName);
    setNickname(nickname);
    setPhoneNumber(phoneNumber);
    setDarkestSecret(darkestSecret);
};

void displayContact(void)
{
	std::cout << std::setw(10) << getIndex() << std::endl;
};