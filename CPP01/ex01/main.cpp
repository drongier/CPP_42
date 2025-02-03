/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:34 by drongier          #+#    #+#             */
/*   Updated: 2025/02/03 19:00:26 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

class Zombie {
public:
    Zombie(std::string name) : name(name) {}
    void announce() {
        std::cout << name << " says BraiiiiiiinnnzzzZ..." << std::endl;
    }
private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return horde;
}

int main() {
    int N = 5;
    std::string name = "ZombieHorde";
    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}