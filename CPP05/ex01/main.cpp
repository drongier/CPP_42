#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== TEST 1: Bureaucrat Exceptions ===" << std::endl;
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

    std::cout << "\n=== TEST 2: Form Creation Valid ===" << std::endl;
    try {
        Form validForm("ValidForm", 50, 30);
        std::cout << validForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Form Creation Invalid (Grade too high) ===" << std::endl;
    try {
        Form invalidForm1("InvalidForm1", 0, 30); // Grade 0 invalide
        std::cout << invalidForm1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Form Creation Invalid (Grade too low) ===" << std::endl;
    try {
        Form invalidForm2("InvalidForm2", 50, 151); // Grade 151 invalide
        std::cout << invalidForm2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Successful Form Signing ===" << std::endl;
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

    std::cout << "\n=== TEST 6: Failed Form Signing (Grade too low) ===" << std::endl;
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

    std::cout << "\n=== TEST 7: Signing Already Signed Form ===" << std::endl;
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

    std::cout << "\n=== TEST 8: Direct beSigned() call ===" << std::endl;
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

    std::cout << "\n=== TEST 9: Direct beSigned() call - Grade too low ===" << std::endl;
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

    std::cout << "\n=== TEST 10: Edge Case - Exact Grade Match ===" << std::endl;
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

    return 0;
}