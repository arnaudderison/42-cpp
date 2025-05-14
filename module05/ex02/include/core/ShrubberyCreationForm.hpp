#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm{
    private:
       ShrubberyCreationForm();
    public:
       ShrubberyCreationForm& operator(const ShrubberyCreationForm& other);
       ShrubberyCreationForm(cosnt ShrubberyCreationForm& other);
       ShrubberyCreationForm(const std::string& target);
       ~ShrubberyCreationForm();
       //jobs
        void execute(const Bureaucrat& executor) const;

};