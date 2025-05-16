#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	void	makeSound( void ) const;

	Dog();
	Dog( const Dog& src );
	Dog& operator=( const Dog& src );
	~Dog();

	std::string getBrainIdea(int index) const;

private:
	Brain* _brain;
};

#endif