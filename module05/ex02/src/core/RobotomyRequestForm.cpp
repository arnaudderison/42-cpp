#include "RobotomyRequestForm.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45, target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecutability(executor);

    std::cout << "* drilling noise *" << std::endl;

    if(std::rand % 2 == 0) {
        std::cout << "Target [" << getTarget() << "] has been rebotomised successfuly!" << std::endl;
    } else {
        std::cout << "Robotomy failed on target [" << getTarget() << "]..." << std::endl;
    }
}
