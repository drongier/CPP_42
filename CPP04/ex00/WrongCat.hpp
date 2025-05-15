#ifndef WROngCat_HPP
#define WROngCat_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        std::string		getType( void ) const;
        void	makeSound( void ) const;

        WrongCat( void );
        WrongCat( const WrongCat& src);
        WrongCat& operator=( const WrongCat& src );
        ~WrongCat();
};

#endif