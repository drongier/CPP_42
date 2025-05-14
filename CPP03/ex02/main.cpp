/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:34 by drongier          #+#    #+#             */
/*   Updated: 2025/05/14 14:40:29 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	ClapTrap robot1("R2D2");
	ScavTrap robot2("C3PO");
	FragTrap robot3("BB8");

	std::cout << std::endl;
	
	std::cout << "ATTACK PHASE" << std::endl;

	robot2.attack("R2D2");
	robot1.takeDamage(robot2.getAttackDamage());
	
	robot2.attack("R2D2");
	robot1.takeDamage(robot2.getAttackDamage());

	robot3.attack("C3P0");
	robot2.takeDamage(robot3.getAttackDamage());

	std::cout << std::endl;

	std::cout << "REGEN PHASE" << std::endl;
	
	robot1.beRepaired(10);
	robot2.beRepaired(10);
	robot3.beRepaired(28);

	std::cout << "UTILITY PHASE" << std::endl;
	
	robot2.guardGate();
	robot3.hiveFivesGuys();

	std::cout << std::endl;
	return (0);
}