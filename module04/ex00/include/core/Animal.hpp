#pragma once
#include <string>

class Animal
{
  protected:
    std::string type;
  public:
    Animal();
    Animal(const Animal &src);
    virtual ~Animal();
    Animal &operator=(const Animal &rhs);

    virtual void makeSound() const;
    std::string getType() const;
};
