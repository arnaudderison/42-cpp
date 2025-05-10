#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_learnInventory[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		~MateriaSource(void);

		MateriaSource const	&operator=(MateriaSource const &copy);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const &type);
		int 				inLearnInventory(AMateria *materia);
};
