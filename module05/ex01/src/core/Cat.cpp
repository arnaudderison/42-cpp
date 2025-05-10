#include "Cat.hpp"
#include "Color.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = src.type;
    this->_brain = new Brain(*src._brain);
}

Cat &Cat::operator=(const Cat &other) {
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

Cat::~Cat() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Meow Meow" << std::endl;
}

const std::string Cat::getIdeas(void) const
{
	return (this->_brain->getIdeas());
}

const std::string Cat::getIdea(unsigned int index) const
{
    return (this->_brain->getIdea(index));
}

void Cat::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
