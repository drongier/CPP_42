/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:52:34 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 15:52:35 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA 
{
private:
    std::string name;
    Weapon& weapon;  // Référence à une arme (toujours initialisée)

public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif