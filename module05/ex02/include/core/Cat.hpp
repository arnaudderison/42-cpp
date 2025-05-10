#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain *_brain;

  public:
    Cat();
    Cat(const Cat &src);
    ~Cat();
    Cat &operator=(const Cat &other);

    void makeSound() const;
    const std::string getIdeas(void) const;
    const std::string getIdea(unsigned int index) const;
		void setIdea(size_t i, std::string idea);
};
