#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		/* Constructors & Destructors */
		Character(void);
		Character(std::string const &name);
		Character(Character const &copy);
		~Character(void);

		/* Basic Operators */
		Character const	&operator=(Character const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		void				setName(std::string const &name);

		/* Main Member Functions */
		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
		int 			inInventory(AMateria *m);
};
