#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Color.hpp"

void printTitle(const std::string& title) {
    std::cout << YELLOW << "\n=== " << title << " ===\n" << RESET;
}

void testFormSignedOK() {
    printTitle("Bureaucrat signs form successfully");
    Bureaucrat b("Alice", 10);
    Form f("LeaveRequest", 20, 50);

    std::cout << BLUE << "[INFO] " << RESET << f << std::endl;
    b.signForm(f);
    std::cout << GREEN << "[RESULT] " << RESET << f << std::endl;
}

void testFormSignedFail() {
    printTitle("Bureaucrat fails to sign (grade too low)");
    Bureaucrat b("Bob", 140);
    Form f("TopSecret", 100, 50);

    std::cout << BLUE << "[INFO] " << RESET << f << std::endl;
    b.signForm(f);
    std::cout << GREEN << "[RESULT] " << RESET << f << std::endl;
}

void testFormCreationInvalid() {
    printTitle("Invalid form creation throws");

    try {
        Form f("TooHigh", 0, 50);
    } catch (std::exception& e) {
        std::cerr << RED << "[EXCEPTION] " << RESET << "TooHigh: " << e.what() << std::endl;
    }

    try {
        Form f("TooLow", 10, 151);
    } catch (std::exception& e) {
        std::cerr << RED << "[EXCEPTION] " << RESET << "TooLow: " << e.what() << std::endl;
    }
}

int main() {
    testFormSignedOK();
    testFormSignedFail();
    testFormCreationInvalid();
    return 0;
}
