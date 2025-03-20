/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:59:06 by drongier          #+#    #+#             */
/*   Updated: 2025/02/10 13:41:43 by drongier         ###   ########.fr       */
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
	std::cout << "ClapTrap " << _name << " constructed ! " << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src) {

	_name = src._name;
	std::cout << "ClapTrap coucou copy" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		std::cout << "Coucou je suis operator" << std::endl;	
	}
	return *this;
}
