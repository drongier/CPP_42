#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    ClapTrap clapTrap("Pip");
    ScavTrap scavTrap("Scavy");
    
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.takeDamage(10);
    clapTrap.attack("Enemy");
    
    scavTrap.attack("Enemy");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(20);
    scavTrap.guardGate();
    
    return (0);
}