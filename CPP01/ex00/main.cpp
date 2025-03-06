/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:39:27 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 14:46:18 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void 	randomChump (std::string name);

int main (void)
{
	Zombie *zombie_1;

	zombie_1 = newZombie("XE28");
	zombie_1->announce();
	randomChump("LNA02");
	delete zombie_1;
}