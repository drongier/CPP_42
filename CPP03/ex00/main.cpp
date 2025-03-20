/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:34 by drongier          #+#    #+#             */
/*   Updated: 2025/02/10 13:28:05 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	
	std::cout << robot1.getName() << std::endl;
	robot2 = robot1;
	ClapTrap copy(robot2);
	std::cout << copy.getName() << std::endl;
	return (0);
}