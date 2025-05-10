#include "Ice.hpp"

//constructor
Ice::Ice(): AMateria("ice") {
    std::cout << "Default constructor in Ice Called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
    std::cout << "Ice copied 🧊" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if(this != &other){
      AMateria::operator=(other);
    }
    std::cout << "Ice assigned 🧊" << std::endl;
    return *this;
}

AMateria* Ice::clone() const{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

//destructor
Ice::~Ice()
{
    std::cout << "Destructor Called in Ice" << std::endl;
}
