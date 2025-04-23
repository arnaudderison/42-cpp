#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: public AMateria {
  // private:
  //   const std::string _type;

  public:
  Cure(void);
    ~Cure(void);
    Cure(const Cure& other); 
    Cure &operator=(const Cure& other);

    AMateria* clone(void) const;
    void use(ICharacter&);
};
