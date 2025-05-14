#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm() {} //pas utile car il est en private
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyForm", 145, 137, target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if(this != &other) {
        this-> _isSigned = other._isSigned;
    }   
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
   checkExecutability(executor);

    std::ofstream out (getTarget() + "_shrubbery");
    out << "       _-_\n"
        << "    /~~   ~~\\\n"
        << " /~~         ~~\\\n"
        << "{               }\n"
        << " \\  _-     -_  /\n"
        << "   ~  \\\\ //  ~\n"
        << "_- -   | | _- _\n"
        << "  _ -  | |   -_\n"
        << "      // \\\\" << std::endl;
    out.close();
}
