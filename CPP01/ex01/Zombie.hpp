/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:45:18 by drongier          #+#    #+#             */
/*   Updated: 2025/03/05 15:46:27 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string _name;

    public:
		Zombie();
		~Zombie();

		void setName(std::string name);
		void announce( void ); 
};

Zombie* zombieHorde( int N, std::string name );

#endif
