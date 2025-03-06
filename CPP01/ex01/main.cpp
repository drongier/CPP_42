/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:34 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 14:48:36 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce();

		delete[] horde; // Libération de la mémoire
	}

	return 0;
}
