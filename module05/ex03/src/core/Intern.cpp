#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum FormType {
    PRESIDENT,
    ROBOTOMY,
    SHRUBBERY,
    DEFAULT
};

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) : 
    _name(other._name),
    _target(other._target) {}

Intern& Intern::operator=(const Intern& other) {
    if(this != &other) {
        this->_name = other._name;
        this->_target = other._target;
    }
    return *this;
}

Intern::Intern(const std::string name, const std::string target) : 
    _name(name),
    _target(target) {}


int typeForm(const std::string& name) {
    if(name == "PresidentialPardonForm")
        return PRESIDENT;
    if(name == "RobotomyRequestForm")
        return ROBOTOMY;
    if(name == "ShrubberyCreationForm")
        return SHRUBBERY;
    return DEFAULT;
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
    AForm* form = NULL;

    switch (typeForm(name))
    {
        case PRESIDENT:
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates" << "PresidentialPardonForm" << std::endl;
            break;
        case ROBOTOMY:
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates" << "RobotomyRequestForm" << std::endl;
            break;
        case SHRUBBERY:
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern create " << "ShrubberyCreationForm" << std::endl;
            break;
        default:
            throw (AForm::InvalidFormException());
            break;
    }
    
    return form;
}