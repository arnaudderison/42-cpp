#include "WrongAnimal.hpp"
#include "Color.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor with type called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "** WrongAnimal sound **" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
