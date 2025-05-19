#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    try {
        printHeader("Creating Bureaucrats");
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("aderison", 140);
        Bureaucrat joe("nosirdea", 50);

        printHeader("Creating Forms: ok");
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Rick");

        printHeader("Attempting to execute unsigned forms");
        joe.executeForm(shrub);
        joe.executeForm(robo);
        joe.executeForm(pardon);  // pas encore signé

        printHeader("Signing forms");
        jim.signForm(shrub);      // OK
        joe.signForm(robo);       // OK
        bob.signForm(pardon);     // OK (grade 1 < 25)

        printHeader("Trying to execute with insufficient grade");
        jim.executeForm(shrub);   // KO
        joe.executeForm(robo);    // KO
        joe.executeForm(pardon);  // KO (grade 50 > 5)

        printHeader("Executing with sufficient grade");
        bob.executeForm(shrub);
        bob.executeForm(robo);
        bob.executeForm(pardon);  // OK : affiche message de grâce

        printHeader("Robotomy randomness");
        for (int i = 0; i < 5; ++i) {
            bob.executeForm(robo);
        }

    } catch (const std::exception& e) {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    return 0;
}
