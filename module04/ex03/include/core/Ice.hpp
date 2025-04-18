#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria {
  // private:
  //   const std::string _type;

  public:
    Ice(void);
    ~Ice(void);
    Ice(const Ice& other); 
    Ice &operator=(const Ice& other);

    AMateria* clone(void) const;
    void use(ICharacter&);
};
