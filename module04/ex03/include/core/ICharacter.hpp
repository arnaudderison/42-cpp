#include <string>
#include <iostream>

class ICharacter
{
  protected:
    ICharacter();
    ICharacter(const ICharacter &other);
    ICharacter& operator=(const ICharacter& other);

  public:
    // constructor

    //overload

    virtual const std::string& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;

    //Destructor
    virtual ~ICharacter() {}
  };
  