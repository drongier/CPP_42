#include <iostream>
#include "../includes/Phonebook.hpp"
#include <limits>

PhoneBook::PhoneBook(void)
{
	std::cout << "\033[2J\033[1;1H";
	size = 0;
	std::cout << "PHONEBOOK28 BONJOUR" << std::endl;
	std::cout << "Type 'ADD', 'SEARCH' or 'EXIT' to use" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl << "Thanks for using PHONEBOOK28" << std::endl;
}

void PhoneBook::deleteOldest(void)
{
	for (size_t i = 0; i < 7; ++i)
	{
		contacts[i] = contacts[i + 1];
		contacts[i].setIndex(i);
	}
	size--;
}

void PhoneBook::addContact(void)
{
	if (size == 8)
		deleteOldest();
	contacts[size].addContact(size);
	if (size < 8)
		size++;
}

size_t PhoneBook::getSize(void) const
{
    return size;
}

void PhoneBook::searchContact(void)
{
	if (size == 0)
	{
		std::cout << std::endl << "Nothing in this phonebook !" << std::endl;
		return ;
	}
	// std::cout << std::endl << "Loading...." << std::endl;
	std::cout << std::setw(10) << "INDEX" << " | "
        		<< std::setw(10) << "NAME" << " | "
				<< std::setw(10) << "SURNAME" << " | "
				<< std::setw(10) << "NICKNAME" << " | "
				<< std::endl;
	for (size_t i = 0; i < size; i++)
    {
        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << contacts[i].getFirstName() << " | "
                  << std::setw(10) << contacts[i].getLastName() << " | "
                  << std::setw(10) << contacts[i].getNickName() << " | "
                  << std::endl;
    }
	size_t index;
    std::cout << std::endl << "---------------------------------------------" << std::endl;
    while (true)
    {
        std::cout << "Enter the index of the contact to display: ";
        std::cin >> index;

        if (std::cin.fail() || index >= size)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
        else
        {
            break;
        }
    }
	std::cout << "\033[2J\033[1;1H";
    contacts[index].displayContact();
};

void PhoneBook::displayContact(size_t index) const
{
    if (index < size) {
        contacts[index].displayContact();
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}
