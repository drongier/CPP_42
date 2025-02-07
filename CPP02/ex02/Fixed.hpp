#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;  // Valeur du nombre à virgule fixe
    static const int _fractionalBits = 8;  // Nombre de bits fractionnaires

public:
    Fixed();  // Constructeur par défaut
    Fixed(const int value);  // Constructeur prenant un entier
    Fixed(const float value);  // Constructeur prenant un flottant
    Fixed(const Fixed& other);  // Constructeur de copie
    Fixed& operator=(const Fixed& other);  // Opérateur d'affectation par copie
    ~Fixed();  // Destructeur

    int getRawBits() const;  // Retourne la valeur brute
    void setRawBits(int const raw);  // Définit la valeur brute

    float toFloat() const;  // Convertit en flottant
    int toInt() const;  // Convertit en entier
};

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif