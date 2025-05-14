#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm() {} //pas utile car il est en private
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyForm", 145, 137, target) {}

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
