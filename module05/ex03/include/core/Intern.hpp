#pragma once

#include "AForm.hpp"
#include <string>

class AForm;

class Intern {
    private:
        std::string _name;
        std::string _target;
    public:
        Intern();
        ~Intern();
        Intern& operator=(const Intern& other);
        Intern(const Intern& other);

        Intern(const std::string name, const std::string target);

        AForm* makeForm(const std::string name, const std::string target);
};
