#include "Dog.hpp"
#include "Color.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = src.type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Woof Woof" << std::endl;
}