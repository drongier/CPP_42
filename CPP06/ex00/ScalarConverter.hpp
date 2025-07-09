// ScalarConverter.hpp
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>

class ScalarConverter {
private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();

    // Méthodes helper privées
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isSpecial(const std::string& str);

public:
    static void convert(const std::string& str);
};

#endif