/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:45:42 by drongier          #+#    #+#             */
/*   Updated: 2025/02/04 17:03:47 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon 
{
private:
    std::string type;  // Attribut privé

public:
    // Constructeur
    Weapon(std::string type);

    // Getter pour type (retourne une référence constante)
    const std::string& getType() const;

    // Setter pour type
    void setType(std::string newType);
};
#endif