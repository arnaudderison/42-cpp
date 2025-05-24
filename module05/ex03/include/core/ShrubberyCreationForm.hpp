#pragma once

#include "AForm.hpp"
#include <string>

class AForm;

class ShrubberyCreationForm : public AForm {
    private:
       ShrubberyCreationForm();
    public:
       ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
       ShrubberyCreationForm(const ShrubberyCreationForm& other);
       ShrubberyCreationForm(const std::string& target);
       ~ShrubberyCreationForm();
       //jobs
        void execute(const Bureaucrat& executor) const;

};