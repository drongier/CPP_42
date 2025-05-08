/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:53:54 by drongier          #+#    #+#             */
/*   Updated: 2025/05/08 14:20:38 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap 
{
	protected:
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
		
		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage ( void ) const;
		
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amout );
		void	beRepaired( unsigned int amout );
};

#endif