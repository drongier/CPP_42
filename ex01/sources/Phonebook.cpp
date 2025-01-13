#include <iostream>
#include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	size = 0;
	std::cout << "PHONEBOOK BONJOUR" << std::endl;
	std::cout << "Type 'ADD', 'SEARCH' or 'EXIT' to use" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "Thanks using PHONEBOOK" << std::endl;
}

void	PhoneBook::addContact(void)
{
	// if (current_size == 8)
	// 	deleteOldestContact();
	contacts[size].addContact();
	if (size < 8)
		size++;
}