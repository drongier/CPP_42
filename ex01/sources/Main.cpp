/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:39 by drongier          #+#    #+#             */
/*   Updated: 2025/01/10 14:19:00 by drongier         ###   ########.fr       */
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
		else if (input == "ADD")
			book.addContact();
	}
}