#include "WrongCat.hpp"
#include "Color.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor of copy called" << std::endl;
    this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operator of assignment is called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << YELLOW << "[INFO]: " << RESET;
    std::cout << "WrongCat sound: ";
    std::cout << "Meow Meow" << std::endl;
}
// WrongCat::makeSound() const {