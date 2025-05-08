/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:59:06 by drongier          #+#    #+#             */
/*   Updated: 2025/05/08 16:52:43 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
}

ClapTrap::ClapTrap(std::string name) : 
	_name(name), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0)
{
	std::cout << "ClapTrap default " << _name << ", constructed ! " << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	std::cout << "ClapTrap " << _name << "assignement operator" << std::endl;	
	return *this;
}

std::string ClapTrap::getName( void ) const {
	return (_name);
}

unsigned int ClapTrap::getHitPoints( void ) const {
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage( void ) const {
	return (_attackDamage);
}

void ClapTrap::attack ( const std::string& target) {
	if (_energyPoints && _hitPoints)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " damages" << std::endl;
		std::cout << "ClapTrap " << _name << " energy point left : " << _energyPoints << std::endl;
	}
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " Need to recharge !" << std::endl;
}

void ClapTrap::takeDamage ( unsigned int amout ) {
	if (_hitPoints)
	{
		_hitPoints -= amout;
		std::cout << "ClapTrap " << _name << " has taken : " << amout;
		std::cout << " domage ! " << std::endl; 
	}
	else
		std::cout << "ClapTrap " << _name << " is dead " << std::endl;  
}

void ClapTrap::beRepaired ( unsigned int amout ) {
	if (_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " regen : " << amout << std::endl;
		_hitPoints += amout;
		std::cout << "ClapTrap " << _name << " has " << _energyPoints << " hitPoints" << std::endl<< std::endl; 
	}
	else
	{
		std::cout << "ClapTrap " << _name << " energyPoints are to low to regen" << std::endl;
		std::cout << "ClapTrap " << _name << " has " << _energyPoints << " hitPoints" << std::endl<< std::endl;
	}
}

