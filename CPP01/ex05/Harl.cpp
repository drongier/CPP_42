#include "Harl.hpp"
#include <iostream>

// Définitions des fonctions membres privées
void Harl::debug() {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Définition de la fonction membre publique
void Harl::complain(std::string level) {
    // Tableau de pointeurs vers les fonctions membres
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // Tableau des niveaux correspondants
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Parcours des niveaux pour trouver celui qui correspond
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // Appel de la fonction correspondante
            (this->*functions[i])();
            return;
        }
    }

    // Si le niveau n'est pas reconnu
    std::cout << "[UNKNOWN] Invalid complaint level." << std::endl;
}