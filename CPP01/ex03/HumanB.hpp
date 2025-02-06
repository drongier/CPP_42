#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointeur vers une arme (peut être nullptr)

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif