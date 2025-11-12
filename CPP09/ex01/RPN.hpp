/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:20 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:21 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept> 
#include <iostream>

class RPN {
	private: 
		std::stack<int> _stack;
	public:
		RPN();
		int calculate(const std::string& expression);
};
