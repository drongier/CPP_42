/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:08 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:09 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	try {	
		if (ac != 2) { 
			std::cerr << "Error : input" << std::endl;
			return (1);
		}

		RPN rpn;
		int result = rpn.calculate(av[1]);
		std::cout << result << std::endl;
		
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}