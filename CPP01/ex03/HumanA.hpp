#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Référence à une arme (toujours initialisée)

public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif