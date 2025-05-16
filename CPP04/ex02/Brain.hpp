#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain( const Brain& src );
	Brain& operator=( const Brain &src );
    ~Brain();

	std::string	getIdea( size_t index ) const;
	void setIdea(size_t index, const std::string& idea);
};

#endif