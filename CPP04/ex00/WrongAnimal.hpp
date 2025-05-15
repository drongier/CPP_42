#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal 
{
    protected :
        std::string	type;

    public :
        std::string		getType( void ) const;
        void	makeSound( void ) const;

        WrongAnimal( void );
        WrongAnimal( const WrongAnimal& src);
        WrongAnimal& operator=( const WrongAnimal& src );
        ~WrongAnimal();
};

#endif