/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:34 by drongier          #+#    #+#             */
/*   Updated: 2025/05/14 16:16:45 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");

	std::cout << std::endl;
	std::cout << "ATTACK PHASE" << std::endl;
	
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
	{
		robot1.attack("C3PO");
		robot2.takeDamage(robot1.getAttackDamage());
		std::cout << std::endl;
	}

	std::cout << "REGEN PHASE" << std::endl;
	
	robot2.beRepaired(10);
	robot1.beRepaired(10);
	
	std::cout << std::endl;

	return (0);
}