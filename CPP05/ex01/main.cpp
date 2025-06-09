#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║        FORM SIGNING TESTS COMPLETED       ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    std::cout << "\n\033[1;36m═══ TEST : BUREAUCRAT EXCEPTIONS ═══\033[0m\n";
    try {
        Bureaucrat b1("Jean", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); 
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST : FORM CREATION VALID ═══\033[0m\n";
    try {
        Form validForm("ValidForm", 50, 30);
        std::cout << validForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST : FORM CREATION INVALID (GRADE TOO HIGH) ═══\033[0m\n";
    try {
        Form invalidForm1("InvalidForm1", 0, 30);
        std::cout << invalidForm1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST : FORM CREATION INVALID (GRADE TOO LOW) ═══\033[0m\n";
    try {
        Form invalidForm2("InvalidForm2", 50, 151);
        std::cout << invalidForm2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST : SUCCESSFUL FORM SIGNING ═══\033[0m\n";
    try {
        Bureaucrat alice("Alice", 25);
        Form importantForm("ImportantForm", 30, 20);
        
        std::cout << alice << std::endl;
        std::cout << importantForm << std::endl;
        
        alice.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST : FAILED FORM SIGNING (GRADE TOO LOW) ═══\033[0m\n";
    try {
        Bureaucrat charlie("Charlie", 100);
        Form secretForm("SecretForm", 50, 30);
        
        std::cout << charlie << std::endl;
        std::cout << secretForm << std::endl;
        
        charlie.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST : EDGE CASE - EXACT GRADE MATCH ═══\033[0m\n";
    try {
        Bureaucrat exactGrade("ExactGrade", 42);
        Form borderForm("BorderForm", 42, 30);
        
        std::cout << exactGrade << std::endl;
        std::cout << borderForm << std::endl;
        
        exactGrade.signForm(borderForm);
        std::cout << borderForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║        FORM SIGNING TESTS COMPLETED       ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    return 0;
}