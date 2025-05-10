#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private :
    Brain *_brain;
  public:
    Dog();
    Dog(const Dog &src);
    ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;
    const std::string getIdeas(void) const;
    const std::string getIdea(unsigned int index) const;
		void setIdea(size_t i, std::string idea);
};
