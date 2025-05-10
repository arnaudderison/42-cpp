#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &copy);
		IMateriaSource const	&operator=(IMateriaSource const &copy);
        
	public:
		/* Constructors & Destructors */
		virtual ~IMateriaSource() {}

		/* Main Member Functions */
		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};