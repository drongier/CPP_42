#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal 
{
    protected :
        std::string	type;

    public :
        std::string		getType( void ) const;
        virtual void	makeSound( void ) const = 0;

        AAnimal( void );
        AAnimal( const AAnimal& src);
        AAnimal& operator=( const AAnimal& src );
        virtual ~AAnimal();
};

#endif