#include "Cat.hpp"
#include "Color.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = src.type;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Meow Meow" << std::endl;
}
