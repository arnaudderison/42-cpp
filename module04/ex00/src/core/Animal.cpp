#include "Animal.hpp"
#include "Color.hpp" 

Animal::Animal() : type("Animal") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &rhs) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
Animal::~Animal() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
