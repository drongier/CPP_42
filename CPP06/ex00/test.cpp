#include <iostream>
#include <limits>

#include <iostream>
#include <vector>

#include <string>
#include <cctype>
#include <regex>

enum class LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    INVALID
};

class TypeDetector {
private:
    static bool isPseudoLiteral(const std::string& str) {
        return (str == "nan" || str == "nanf" || 
                str == "inf" || str == "inff" || 
                str == "-inf" || str == "-inff");
    }
    
    static bool isChar(const std::string& str) {
        return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
    }
    
    static bool isInteger(const std::string& str) {
        if (str.empty()) return false;
        
        size_t start = 0;
        if (str[0] == '+' || str[0] == '-') {
            start = 1;
        }
        
        if (start >= str.length()) return false;
        
        for (size_t i = start; i < str.length(); ++i) {
            if (!std::isdigit(str[i])) return false;
        }
        
        return true;
    }
    
    static bool isFloat(const std::string& str) {
        if (str.empty() || str.back() != 'f') return false;
        
        std::string withoutF = str.substr(0, str.length() - 1);
        return isDecimalNumber(withoutF);
    }
    
    static bool isDouble(const std::string& str) {
        return isDecimalNumber(str);
    }
    
    static bool isDecimalNumber(const std::string& str) {
        if (str.empty()) return false;
        
        size_t start = 0;
        if (str[0] == '+' || str[0] == '-') {
            start = 1;
        }
        
        if (start >= str.length()) return false;
        
        bool hasPoint = false;
        bool hasDigit = false;
        
        for (size_t i = start; i < str.length(); ++i) {
            if (str[i] == '.') {
                if (hasPoint) return false; // Deux points
                hasPoint = true;
            } else if (std::isdigit(str[i])) {
                hasDigit = true;
            } else {
                return false;
            }
        }
        
        return hasDigit;
    }

public:
    static LiteralType detectType(const std::string& str) {
        if (isPseudoLiteral(str)) return LiteralType::PSEUDO_LITERAL;
        if (isChar(str)) return LiteralType::CHAR;
        if (isInteger(str)) return LiteralType::INT;
        if (isFloat(str)) return LiteralType::FLOAT;
        if (isDouble(str)) return LiteralType::DOUBLE;
        
        return LiteralType::INVALID;
    }
};


int main() {
    std::vector<std::string> testCases = {
        "42",        // Int
        "42.0f",     // Float
        "42.0",      // Double
        "c",         // Char
        "nan",       // Pseudo-literal
        "inff",      // Pseudo-literal
        "hello",     // Invalid
        "42.5.3",    // Invalid
        "-42",       // Int
        "+42.7f"     // Float
    };
    
    for (const auto& test : testCases) {
        LiteralType type = TypeDetector::detectType(test);
        
        std::cout << "\"" << test << "\" -> ";
        switch (type) {
            case LiteralType::CHAR:
                std::cout << "CHAR";
                break;
            case LiteralType::INT:
                std::cout << "INT";
                break;
            case LiteralType::FLOAT:
                std::cout << "FLOAT";
                break;
            case LiteralType::DOUBLE:
                std::cout << "DOUBLE";
                break;
            case LiteralType::PSEUDO_LITERAL:
                std::cout << "PSEUDO_LITERAL";
                break;
            case LiteralType::INVALID:
                std::cout << "INVALID";
                break;
        }
        std::cout << std::endl;
    }
    
    return 0;
}



