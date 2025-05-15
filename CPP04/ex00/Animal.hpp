#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Dog.hpp"

class Animal 
{
    protected :
        std::string	type;

    public :
        std::string		getType( void ) const;
        virtual void	makeSound( void ) const;

        Animal( void );
        Animal( const Animal& src);
        Animal& operator=( const Animal& src );
        ~Animal();
};

#endif