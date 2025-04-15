#include "Dog.hpp"
#include "Cat.hpp"
#include "Color.hpp"

int main() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Creating an array of Animals" << std::endl;
    Animal *animals[4];

    for (int i = 0; i < 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; i++) {
        animals[i] = new Cat();
    }

    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Making sounds" << std::endl;
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }

    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Deleting the array of Animals" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    return 0;
}