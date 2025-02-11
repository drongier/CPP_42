/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:34 by drongier          #+#    #+#             */
/*   Updated: 2025/02/04 16:03:30 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return horde;
}

int main() 
{
    int N = 5;
    std::string name = "ZombieHorde";
    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}