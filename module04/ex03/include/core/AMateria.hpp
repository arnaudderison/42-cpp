#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
  protected:
    std::string _type;
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria& operator=(const AMateria &other);

  public:
    //constructor

    //Method
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

    //destructor
    virtual ~AMateria();
};
