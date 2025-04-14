#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(std::string name);

		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &other);

		void highFiveGuys(void);

};