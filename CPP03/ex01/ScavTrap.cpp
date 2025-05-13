#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is constructed!" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack! No energy." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}