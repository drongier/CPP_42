#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

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
        virtual ~Animal();
};

#endif