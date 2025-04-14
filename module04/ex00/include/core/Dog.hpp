#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog &src);
    ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;
};
