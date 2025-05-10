#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Création de la source de matières ===" << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << "\n=== Apprentissage des matières ===" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
  src->learnMateria(new Ice());

	std::cout << "\n=== Création d'un personnage ===" << std::endl;
	ICharacter* me = new Character("aderison");

	std::cout << "\n=== Création et équipement des matières ===" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n=== Création d'un autre personnage ===" << std::endl;
	ICharacter* bob = new Character("Bob");

	std::cout << "\n=== Utilisation des matières sur Bob ===" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n=== Nettoyage ===" << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
