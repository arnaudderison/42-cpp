#include "Cure.hpp"

//constructor
Cure::Cure(): AMateria("cure") {
    std::cout << "Default constructor Cure" << std::endl;
}

Cure::Cure(const Cure& other)
{
    std::cout << "Cure copied" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    if(this != &other){
        this->_type = other._type;
    }
    std::cout << "Cure assigned" << std::endl;
    return *this;
}

AMateria* Cure::clone() const{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

//destructor
Cure::~Cure()
{
    std::cout << "Destructor Called in Cure" << std::endl;
}
