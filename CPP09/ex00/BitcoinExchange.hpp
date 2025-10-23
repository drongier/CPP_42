#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _database;
        void loadDatabase(const std::string& csv);

    public:
        BitcoinExchange();
        void printFirstN(int n);
        void processInput(const std::string& inputFile);
        bool isValidDate(const std::string date);
        double getPrice(const std::string& date);
};

#endif
