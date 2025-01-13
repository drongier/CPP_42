/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:39 by drongier          #+#    #+#             */
/*   Updated: 2025/01/13 18:09:41 by drongier         ###   ########.fr       */
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
			std::cout << "Wrong command ";
		else
			std::cout << "Wrong command " << std::endl;
	};
}