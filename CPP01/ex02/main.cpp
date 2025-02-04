/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:25 by drongier          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:48 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string : " << &string << std::endl;
	std::cout << "Address pointer : " << stringPTR << std::endl;
	std::cout << "Address reference :" << &stringREF << std::endl;

	std::cout << "Value of string : " << string << std::endl;
	std::cout << "Value of pointer : " << *stringPTR << std::endl;
	std::cout << "Value of reference : " << stringREF << std::endl;
}