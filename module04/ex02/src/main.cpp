#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 4

int main() {

    std::cout << "\n=== [TEST BASIQUE POLYMORPHISME] ===\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // devrait appeler Dog::~Dog() et Brain::~Brain()
    delete i; // devrait appeler Cat::~Cat() et Brain::~Brain()

    std::cout << "\n=== [TABLEAU D’ANIMAUX] ===\n";
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
        animals[i] = new Cat();

    std::cout << "\n=== [SUPPRESSION DU TABLEAU] ===\n";
    for (int i = 0; i < ARRAY_SIZE; ++i)
        delete animals[i];

    std::cout << "\n=== [COPIE PROFONDE] ===\n";
    Dog basic;
    basic.setIdea(0, "I want a bone!");
    Dog copy = basic; // test copy constructor

    std::cout << "Original Dog Brain Idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea[0]:   " << copy.getIdea(0) << std::endl;

    basic.setIdea(0, "Changed idea!");
    std::cout << "Original Dog Brain Idea[0] (after change): " << basic.getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea[0] (should be unchanged): " << copy.getIdea(0) << std::endl;

    return 0;
}
