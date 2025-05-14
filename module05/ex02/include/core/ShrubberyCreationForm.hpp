#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
       ShrubberyCreationForm();
    public:
       ~ShrubberyCreationForm();
       ShrubberyCreationForm(const std::string& target);
       //jobs
        void execute(const Bureaucrat& executor) const;

};