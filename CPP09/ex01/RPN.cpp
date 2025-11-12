/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:14 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:15 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

int RPN::calculate(const std::string& expression) {

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() != 1) {
			throw std::runtime_error("Error");
		}

		char c = token[0];
		if(isdigit(c)) {
			int num = c - '0';
			_stack.push(num);
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error");
			}

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result;
			if (c == '+')
				result = a + b;
			else if (c == '-')
				result = a - b;
			else if (c == '*')
				result = a * b;
			else if (c == '/') {
				if (b == 0)
					throw std::runtime_error("Error");
				result = a / b;
			}
			_stack.push(result);
		}
		else {
			throw std::runtime_error("Error");
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	return _stack.top();
}
