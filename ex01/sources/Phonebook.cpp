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

void PhoneBook::addContact(void)
{
    if (size == 8) {
        std::cout << std::endl << "8 contacts reached" << std::endl;
        return;
    }
    contacts[size].addContact();
    size++;
}