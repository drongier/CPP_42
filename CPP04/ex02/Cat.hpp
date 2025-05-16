#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat : public AAnimal
{
public:
	void	makeSound( void ) const;

	Cat();
	Cat( const Cat& src );
	Cat& operator=( const Cat& src );
	~Cat();

	void setBrainIdea(size_t index, const std::string& idea);
	std::string getBrainIdea(size_t index) const;

private:
	Brain* _brain;
};

#endif