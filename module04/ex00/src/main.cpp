#include "Dog.hpp"
#include "Cat.hpp"
#include "Color.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Creating an array of Animals" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    Animal *animals[4];

    for (int i = 0; i < 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; i++) {
        animals[i] = new Cat();
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Making sounds" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Deleting the array of Animals" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Creating WrongAnimal and WrongCat" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongCat *wrongCat = new WrongCat();
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Making sounds" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "Deleting WrongAnimal and WrongCat" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    delete wrongAnimal;
    delete wrongCat;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << RED << "[ALERT] " << RESET;
    std::cout << "End of program" << std::endl;

    return 0;
}