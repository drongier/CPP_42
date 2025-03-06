/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:52:46 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 15:52:50 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB 
{
private:
    std::string name;
    Weapon* weapon;  // Pointeur vers une arme (peut être nullptr)

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif