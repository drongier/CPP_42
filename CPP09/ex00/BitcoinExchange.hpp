/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:55:55 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:55:56 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib> 

class BitcoinExchange {
	private:
		std::map<std::string, double> _database;
		void 	loadDatabase(const std::string& csv);
		bool 	isValidDate(const std::string& date);
		double 	getPrice(const std::string& date);
		bool 	isNumeric(const std::string& str, double& value);

	public:
		BitcoinExchange();
		void processInput(const std::string& inputFile);
};

#endif
