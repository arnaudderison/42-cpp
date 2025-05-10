#include "ICharacter.hpp"

// contructor
ICharacter::ICharacter()
{
    std::cout << "Default ICharater Constructor called" << std::endl;
}
ICharacter::ICharacter(const ICharacter &other) {
    std::cout << "contructor of copy called in ICharacter" << std::endl;
    (void) other;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    std::cout << "Operator assignement called in ICharacter" << std::endl;
    (void) other;
    return *this;
}

//Destructor
ICharacter::~ICharacter()
{
    std::cout << "Default ICharater Destructor called" << std::endl;    
}
