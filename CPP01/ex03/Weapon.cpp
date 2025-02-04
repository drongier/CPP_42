#include "Weapon.hpp"

// Constructeur
Weapon::Weapon(std::string type) : type(type) {}

// Getter pour type
const std::string& Weapon::getType() const {
    return type;
}

// Setter pour type
void Weapon::setType(std::string newType) {
    type = newType;
}