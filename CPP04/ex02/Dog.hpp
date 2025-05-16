#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	void	makeSound( void ) const;

	Dog();
	Dog( const Dog& src );
	Dog& operator=( const Dog& src );
	~Dog();

	void setBrainIdea(size_t index, const std::string& idea);
	std::string getBrainIdea(size_t index) const;

private:
	Brain* _brain;
};

#endif