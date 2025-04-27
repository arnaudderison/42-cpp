#pragma once
#include <string>

class Animal
{
  protected:
    std::string type;

    Animal();
    Animal(const std::string &type);
    Animal(const Animal &src);

    Animal &operator=(const Animal &rhs);

  public:
    virtual ~Animal();
    virtual void makeSound() const = 0;
    std::string getType() const;
};
