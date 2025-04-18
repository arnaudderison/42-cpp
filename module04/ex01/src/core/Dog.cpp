#include "Dog.hpp"
#include "Color.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = src.type;
    this->_brain = new Brain(*src._brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->_brain)
                delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Woof Woof" << std::endl;
}

const std::string Dog::getIdeas(void) const
{
	return (this->_brain->getIdeas());
}

const std::string Dog::getIdea(unsigned int index) const
{
    return (this->_brain->getIdea(index));
}

void Dog::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}