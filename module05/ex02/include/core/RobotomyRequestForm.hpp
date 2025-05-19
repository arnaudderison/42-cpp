#pragma once

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"
#include <ostream>

class AForm;

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
};