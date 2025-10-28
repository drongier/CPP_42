/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:43:18 by drongier          #+#    #+#             */
/*   Updated: 2025/10/27 17:43:19 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"
 
int main()
{
    std::vector<int> v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    v.push_back(6);
    v.push_back(9);
 
	// test 1
	
	std::cout << "TEST 1" <<std::endl;
	
	int val = 9;
	std::cout << "Looking for " << val << std::endl;
	std::cout << "Into vector : ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << std::endl;

	::easyfind(v, val);
	std::cout << std::endl;

	//test 2
	
	std::cout << "TEST 2" <<std::endl;
	
	val = 28;
	std::cout << "Looking for " << val << std::endl;
	std::cout << "Into vector : ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << std::endl;

	::easyfind(v, val);
	std::cout << std::endl;

    return 0;
}