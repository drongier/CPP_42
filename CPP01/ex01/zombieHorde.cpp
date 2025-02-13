/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:44:25 by drongier          #+#    #+#             */
/*   Updated: 2025/02/13 14:59:43 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name) {
    // Allouer uniquement la mémoire pour N Zombies sans appeler le constructeur
    Zombie* horde = static_cast<Zombie*>(operator new[](N * sizeof(Zombie)));

    // Initialiser chaque zombie avec le nom donné en utilisant le placement new
    for (int i = 0; i < N; i++) {
        new (&horde[i]) Zombie(name); // Appeler le constructeur avec le placement new
    }

    // Retourner un pointeur vers le premier zombie
    return horde;
}