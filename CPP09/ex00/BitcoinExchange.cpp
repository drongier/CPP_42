// Quantité de BTC (input.txt) × Prix du BTC (data.csv) = Valeur en $
#include "BitcoinExchange.hpp"
#include <cctype>
#include <stdexcept>

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

bool BitcoinExchange::isNumeric(const std::string& str, double& value) {
    if (str.empty())
        return false;
    
    // Trim les espaces au début/fin si nécessaire
    std::string trimmed = str;
    
    char* endptr;
    errno = 0;
    value = strtod(trimmed.c_str(), &endptr);
    
    // Vérifier qu'on a bien tout parsé
    if (errno != 0 || *endptr != '\0' || endptr == trimmed.c_str())
        return false;
    
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {

    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);
    
    // Vérifier que ce sont des chiffres
    for (size_t i = 0; i < year_str.length(); i++)
        if (!isdigit(year_str[i])) return false;
    for (size_t i = 0; i < month_str.length(); i++)
        if (!isdigit(month_str[i])) return false;
    for (size_t i = 0; i < day_str.length(); i++)
        if (!isdigit(day_str[i])) return false;
    
    // Convertir en entiers
    int year = atoi(year_str.c_str());
    int month = atoi(month_str.c_str());
    int day = atoi(day_str.c_str());
    
    // Vérifier le mois
    if (month < 1 || month > 12)
        return false;
    
    // Jours par mois
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Année bissextile
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        days_in_month[1] = 29;
    
    // Vérifier le jour
    if (day < 1 || day > days_in_month[month - 1])
        return false;
    
    return true;
}

double BitcoinExchange::getPrice(const std::string& date) {
    std::map<std::string, double>::iterator it = _database.find(date);

    if (it != _database.end()){
        return it->second;
    }

    it = _database.lower_bound(date);

    if (it == _database.begin()) {
        throw std::runtime_error("no price available for this date");
    }

    --it;
    return it->second;
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
        size_t pipe_pos = line.find(" | ");

        if (pipe_pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line <<  std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe_pos);
        std::string value_str = line.substr(pipe_pos + 3);

        double value = atof(value_str.c_str());

        if (!isNumeric(value_str, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positiv number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large number." << std::endl;
            continue;  // ← IMPORTANT : ne pas oublier !
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
