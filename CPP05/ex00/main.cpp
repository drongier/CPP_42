/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:38:03 by drongier          #+#    #+#             */
/*   Updated: 2025/06/05 12:58:33 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║           BUREAUCRAT TESTS START          ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    std::cout << "\n\033[1;31m═══ TEST 1: OBJET Grade 0 invalide ═══\033[0m\n";
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;31m═══ TEST 2: Grade 151 invalide ═══\033[0m\n";
    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 3: Grade 1 to 0  ═══\033[0m\n";
    try {
        Bureaucrat nearTop("NearTop", 2);
        std::cout << "Initial: " << nearTop << std::endl;
        
        nearTop.incrementGrade();
        std::cout << "After 1st increment: " << nearTop << std::endl;
        
        nearTop.incrementGrade();
        std::cout << "This line should not appear" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;33m═══ TEST 4: Grade 150 to 151 ═══\033[0m\n";
    try {
        Bureaucrat nearBottom("NearBottom", 149);
        std::cout << "Initial: " << nearBottom << std::endl;
        
        nearBottom.decrementGrade(); 
        std::cout << "After 1st decrement: " << nearBottom << std::endl;
        
        nearBottom.decrementGrade();
        std::cout << "This line should not appear" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 5: CAS LIMITES VALIDES ═══\033[0m\n";
    try {
        Bureaucrat minGrade("MinGrade", 1);
        Bureaucrat maxGrade("MaxGrade", 150);
        
        std::cout << "Minimum valid grade: " << minGrade << std::endl;
        std::cout << "Maximum valid grade: " << maxGrade << std::endl;
        maxGrade.incrementGrade();
        std::cout << "After increment: " << maxGrade << std::endl;
        minGrade.decrementGrade();
        std::cout << "After decrement: " << minGrade << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;36m═══ TEST 6: NEGATIFS ═══\033[0m\n";
    try {
        Bureaucrat negative("Negative", -42);
        std::cout << negative << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;32m═══ TEST 7: OPERATIONS MULTIPLES VALIDES ═══\033[0m\n";
    try {
        Bureaucrat worker("Worker", 75);
        std::cout << "Initial: " << worker << std::endl;
        
        for (int i = 0; i < 5; i++) {
            worker.incrementGrade();
            std::cout << "After increment " << i+1 << ": " << worker << std::endl;
        }
        
        for (int i = 0; i < 3; i++) {
            worker.decrementGrade();
            std::cout << "After decrement " << i+1 << ": " << worker << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;34m╔═══════════════════════════════════════════╗\033[0m\n";
    std::cout << "\033[1;34m║        BUREAUCRAT TESTS COMPLETED         ║\033[0m\n";
    std::cout << "\033[1;34m╚═══════════════════════════════════════════╝\033[0m\n";

    return 0;
}