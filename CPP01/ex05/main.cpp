#include "Harl.hpp"
#include <cstdlib>

int	main( void )
{
	Harl	Harl0;

	Harl0.complain("DEBUG");
	Harl0.complain("INFO");
	Harl0.complain("WARNING");
	Harl0.complain("ERROR");
	Harl0.complain("TEST");

	return (0);
}