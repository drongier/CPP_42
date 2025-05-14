#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap ( std::string name);
	FragTrap ( const FragTrap& src);
	~FragTrap();
	FragTrap& operator=(const FragTrap& src);

	void hiveFivesGuys( void );
};

#endif
