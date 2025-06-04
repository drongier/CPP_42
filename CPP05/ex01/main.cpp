#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║        FORM SIGNING TESTS COMPLETED       ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    std::cout << "\n\033[1;36m═══ TEST 1: BUREAUCRAT EXCEPTIONS ═══\033[0m\n";
    try {
        Bureaucrat b1("Jean", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // passe à 1
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // Exception GradeTooHigh
        std::cout << b1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 2: FORM CREATION VALID ═══\033[0m\n";
    try {
        Form validForm("ValidForm", 50, 30);
        std::cout << validForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 3: FORM CREATION INVALID (GRADE TOO HIGH) ═══\033[0m\n";
    try {
        Form invalidForm1("InvalidForm1", 0, 30); // Grade 0 invalide
        std::cout << invalidForm1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 4: FORM CREATION INVALID (GRADE TOO LOW) ═══\033[0m\n";
    try {
        Form invalidForm2("InvalidForm2", 50, 151); // Grade 151 invalide
        std::cout << invalidForm2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 5: SUCCESSFUL FORM SIGNING ═══\033[0m\n";
    try {
        Bureaucrat alice("Alice", 25);
        Form importantForm("ImportantForm", 30, 20);
        
        std::cout << alice << std::endl;
        std::cout << importantForm << std::endl;
        
        alice.signForm(importantForm); // Alice grade 25 >= required 30, should work
        std::cout << importantForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 6: FAILED FORM SIGNING (GRADE TOO LOW) ═══\033[0m\n";
    try {
        Bureaucrat charlie("Charlie", 100);
        Form secretForm("SecretForm", 50, 30);
        
        std::cout << charlie << std::endl;
        std::cout << secretForm << std::endl;
        
        charlie.signForm(secretForm); // Charlie grade 100 < required 50, should fail
        std::cout << secretForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 7: SIGNING ALREADY SIGNED FORM ═══\033[0m\n";
    try {
        Bureaucrat director("Director", 1);
        Form contract("Contract", 10, 5);
        
        std::cout << director << std::endl;
        std::cout << contract << std::endl;
        
        director.signForm(contract); // First signature
        std::cout << contract << std::endl;
        
        director.signForm(contract); // Try to sign again
        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 8: DIRECT beSigned() CALL ═══\033[0m\n";
    try {
        Bureaucrat manager("Manager", 40);
        Form report("Report", 45, 35);
        
        std::cout << manager << std::endl;
        std::cout << report << std::endl;
        
        report.beSigned(manager); // Direct call to beSigned
        std::cout << report << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 9: DIRECT beSigned() CALL - GRADE TOO LOW ═══\033[0m\n";
    try {
        Bureaucrat intern("Intern", 150);
        Form vipForm("VIPForm", 10, 5);
        
        std::cout << intern << std::endl;
        std::cout << vipForm << std::endl;
        
        vipForm.beSigned(intern); // Should throw exception
        std::cout << vipForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 10: EDGE CASE - EXACT GRADE MATCH ═══\033[0m\n";
    try {
        Bureaucrat exactGrade("ExactGrade", 42);
        Form borderForm("BorderForm", 42, 30);
        
        std::cout << exactGrade << std::endl;
        std::cout << borderForm << std::endl;
        
        exactGrade.signForm(borderForm); // Grade 42 == required 42, should work
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