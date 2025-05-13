/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:34 by drongier          #+#    #+#             */
/*   Updated: 2025/05/09 17:19:34 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
	ClapTrap robot1("R2D2");
	ScavTrap robot2("C3PO");

	std::cout << std::endl;
	
	std::cout << "ATTACK PHASE" << std::endl;

	for (size_t i = 0; i <= 10; i++)
	{
		robot2.attack("C3P0");
		robot1.takeDamage(robot2.getAttackDamage());
		if (robot2.getHitPoints() == 0)
		break;
		std::cout << std::endl;
	}

	std::cout << "REGEN PHASE" << std::endl;
	
	robot2.beRepaired(10);
	robot1.beRepaired(10);

	std::cout << "UTILITY PHASE" << std::endl;
	
	robot2.guardGate();

	std::cout << std::endl;
	return (0);
}