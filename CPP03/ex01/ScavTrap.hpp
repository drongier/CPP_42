#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& src );
	~ScavTrap();
	ScavTrap& operator=( const ScavTrap& src );

	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif