/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:20:17 by drongier          #+#    #+#             */
/*   Updated: 2025/03/06 12:20:18 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

int	main( void )
{
	Harl	Harl0;

	Harl0.complain("DEBUG");
	Harl0.complain("INFO");
	Harl0.complain("WARNING");
	Harl0.complain("ERROR");
	Harl0.complain("TEST");

	return (0);
}