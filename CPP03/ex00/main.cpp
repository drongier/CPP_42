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
	ClapTrap clapTrap("Pip");
	
	clapTrap.attack("Enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.takeDamage(10);
	clapTrap.attack("Enemy");
	
	return (0);
}