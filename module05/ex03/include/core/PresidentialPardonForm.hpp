#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class AForm;


class PresidentialPardonForm: public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat& executor) const;
};