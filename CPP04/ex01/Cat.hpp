#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
public:
	void	makeSound( void ) const;

	Cat();
	Cat( const Cat& src );
	Cat& operator=( const Cat& src );
	~Cat();

	Brain* getBrain() const { return _brain; }

private:
	Brain* _brain;
};

#endif