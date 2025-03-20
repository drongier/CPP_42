/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:53:54 by drongier          #+#    #+#             */
/*   Updated: 2025/02/10 12:59:49 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name);
		ClapTrap( const ClapTrap& src);
		ClapTrap& operator=( const ClapTrap& src );
		~ClapTrap();


		std::string getName() const {
			 return _name;
		}
		
};

#endif