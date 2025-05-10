#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
  protected:
    std::string _type;
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    
  public:
    //constructor
    AMateria();
    AMateria& operator=(const AMateria &other);

    //Method
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

    //destructor
    virtual ~AMateria();
};
