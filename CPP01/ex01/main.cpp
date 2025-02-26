/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:34 by drongier          #+#    #+#             */
/*   Updated: 2025/02/13 14:58:03 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int main() {
    int N = 5;
    std::string name = "ZombieHorde";
    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    // Appeler explicitement le destructeur pour chaque Zombie
    for (int i = 0; i < N; i++) {
        horde[i].~Zombie();
    }

    // Libérer la mémoire allouée
    operator delete[](horde);

    return 0;
}