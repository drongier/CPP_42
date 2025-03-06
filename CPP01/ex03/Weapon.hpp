/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:45:42 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 15:53:43 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon 
{
private:
    std::string type;

public:
    Weapon(std::string type);

    const std::string& getType() const;

    void setType(std::string newType);
};
#endif