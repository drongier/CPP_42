/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:39 by drongier          #+#    #+#             */
/*   Updated: 2025/01/30 16:59:46 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string input;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			break ;
		else if (input.empty())
			continue ;
		else if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else if (input == "SIZE")
			std::cout << "Nombre de contact : " << book.getSize() << std::endl; // Afficher la taille actuelle
        else if (input == "DISPLAY")
        {
            size_t index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;
            book.displayContact(index);
        }
        else
            std::cout << "Wrong command, pls use ADD, SEARCH or EXIT\n";
	};
}