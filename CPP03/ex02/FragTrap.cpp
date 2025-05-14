#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is now alive !" << std::endl;
}
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	std::cout << "FragTrap assignement operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed! " << std::endl;
}

// ----------------------------------------------------------------- //

void FragTrap::hiveFivesGuys()
{
	std::cout << "FragTrap " << _name << " HIVEFIVES !" << std::endl;
}