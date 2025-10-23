// Quantité de BTC (input.txt) × Prix du BTC (data.csv) = Valeur en $
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        std::cout << "Error file csb" << std::endl;

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        std::string date = line.substr(0, comma);
        double price = atof(line.substr(comma + 1).c_str());

        _database[date] = price;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string date) {

}

double BitcoinExchange::getPrice(const std::string& date) {
    
}

void BitcoinExchange::processInput(const std::string& filename) {
    //1) Open file
    std::ifstream file(filename.c_str());
    if(!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); //skip first line with date|value

    while(std::getline(file, line)) {
        std::cout << line << std::endl;
        size_t pipe_pos = line.find(" | ");

        if (pipe_pos == std::string::npos) {
            std::cerr << "Error: bad input";
            continue;
        }

        std::string date = line.substr(0, pipe_pos);
        std::string value_str = line.substr(pipe_pos + 3);

        double value = atof(value_str.c_str());

        if (!isValideDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positiv number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large number." << std::endl;
        }
        try {
            double price = getPrice(date);
            double result = value * price;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::printFirstN(int n) {
    int count = 0;

    for (std::map<std::string, double>::iterator it = _database.begin(); 
         it != _database.end() && count < n; 
         ++it, ++count) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << "=====================" << std::endl;
}
