#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5, target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    return *this;
}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    checkExecutability(executor);
    std::cout << "Target [" << getTarget()
              << "] has been pardoned by Zaphod Beeblebrox." << std::endl;
}
