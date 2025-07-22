#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

ScalarConverter::~ScalarConverter () {

}

// Détection du type char: 'c'
bool ScalarConverter::isChar(const std::string& str) {
    size_t len = str.length();

    if (len == 3) {
        // 'x' ou "x"
        char c0 = str[0];
        char c2 = str[2];
        if ((c0 == '\'' && c2 == '\'') || (c0 == '"' && c2 == '"')) {
            return true;
        }
    } else if (len == 1) {
        return true;
    }
    return false;
}

// Détection du type int: -42, 42, 0
bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

// Détection du type float: 42.0f, -4.2f, nanf, inff
bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty()) return false;
    if (str == "nanf" || str == "+inff" || str == "-inff") return true;
    if (str.back() != 'f') return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    size_t dotCount = 0;
    size_t start = 0;
    
    if (withoutF[0] == '+' || withoutF[0] == '-') start = 1;
    if (start >= withoutF.length()) return false;
    
    for (size_t i = start; i < withoutF.length(); i++) {
        if (withoutF[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        } else if (!std::isdigit(withoutF[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

// Détection du type double: 42.0, -4.2, nan, inf
bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty()) return false;
    if (str == "nan" || str == "+inf" || str == "-inf") return true;
    
    size_t dotCount = 0;
    size_t start = 0;
    
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

// Détection des valeurs spéciales
bool ScalarConverter::isSpecial(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "-inf" || 
            str == "+inff" || str == "-inff");
}

// Conversion principale
void ScalarConverter::convert(const std::string& str) {

    if (isInt(str)) {
        std::stringstream ss(str);
        long long value;
        ss >> value;
        
        // Vérification overflow int
        if (value > INT_MAX || value < INT_MIN) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        
        int intValue = static_cast<int>(value);
        
        // Conversion char
        if (intValue >= 32 && intValue <= 126) {
            std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
        } else if (intValue >= 0 && intValue <= 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
    }

    else if (isChar(str)) {
    char c;
        if (str.length() == 1)
            c = str[0];
     else
            c = str[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isSpecial(str)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        
        if (str == "nanf" || str == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (str == "+inff" || str == "+inf") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else if (str == "-inff" || str == "-inf") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }

    else if (isFloat(str)) {
        std::string withoutF = str.substr(0, str.length() - 1);
        std::stringstream ss(withoutF);
        float floatValue;
        ss >> floatValue;
        
        // Conversion char
        if (floatValue >= 32 && floatValue <= 126 && floatValue == static_cast<int>(floatValue)) {
            std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
        } else if (floatValue >= 0 && floatValue <= 127 && floatValue == static_cast<int>(floatValue)) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        
        // Conversion int
        if (floatValue > INT_MAX || floatValue < INT_MIN || floatValue != floatValue) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
        }
        
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
    }
    else if (isDouble(str)) {
        std::stringstream ss(str);
        double doubleValue;
        ss >> doubleValue;
        
        // Conversion char
        if (doubleValue >= 32 && doubleValue <= 126 && doubleValue == static_cast<int>(doubleValue)) {
            std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
        } else if (doubleValue >= 0 && doubleValue <= 127 && doubleValue == static_cast<int>(doubleValue)) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        
        // Conversion int
        if (doubleValue > INT_MAX || doubleValue < INT_MIN || doubleValue != doubleValue) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
        }
        
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    }
    else {
        std::cout << "Error: Invalid input format" << std::endl;
    }
}