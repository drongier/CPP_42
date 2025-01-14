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
    if (size == 8) 
	{
        std::cout << std::endl << "8 contacts reached" << std::endl;
        return;
    }
    contacts[size].addContact(size);
    size++;
}

size_t PhoneBook::getSize(void) const
{
    return size;
}

void PhoneBook::searchContact(void)
{
	size_t i = 0;

	if (size == 0)
	{
		std::cout << std::endl << "Nothing in this phonebook !" << std::endl;
		return ;
	}
	std::cout << std::endl << "Loading...." << std::endl;
	std::cout << std::endl << "INDEX | NAME | SURNAM | NICKNAME |" << std::endl;
	while (i < size)
	{
		contacts[i].displayContact();
	}

};