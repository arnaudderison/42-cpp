#include "Bureaucrat.hpp"
#include "Color.hpp"

void printTitle(const std::string& title) {
    std::cout << YELLOW << "\n=== " << title << " ===\n" << RESET;
}

void testValidBureaucrat() {
    printTitle("Valid Bureaucrat");
    try {
        Bureaucrat b("Jean", 42);
        std::cout << GREEN << "[OK] " << RESET << b << std::endl;

        b.incrementGrade();
        std::cout << YELLOW << "[INFO] " << RESET << "After increment: " << b << std::endl;

        b.decrementGrade();
        std::cout << YELLOW << "[INFO] " << RESET << "After decrement: " << b << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "[ERROR] " << RESET << e.what() << std::endl;
    }
}

void testTooHigh() {
    printTitle("Grade Too High");
    try {
        Bureaucrat b("Bob", 0);
    } catch (std::exception& e) {
        std::cerr << RED << "[EXCEPTION] " << RESET << e.what() << std::endl;
    }
}

void testTooLow() {
    printTitle("Grade Too Low");
    try {
        Bureaucrat b("Alice", 151);
    } catch (std::exception& e) {
        std::cerr << RED << "[EXCEPTION] " << RESET << e.what() << std::endl;
    }
}

void testAssignment() {
    printTitle("Assignment Operator");
    try {
        Bureaucrat a("Arnaud", 2);
        Bureaucrat b("Bernard", 149);

        std::cout << BLUE << "[BEFORE] " << RESET << "a: " << a << " | b: " << b << std::endl;
        b = a;
        std::cout << GREEN << "[AFTER] " << RESET << "a: " << a << " | b: " << b << std::endl;
        std::cout << YELLOW << "[NOTE] " << RESET << "Le nom de b reste 'Bernard' car il est const." << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "[EXCEPTION] " << RESET << e.what() << std::endl;
    }
}

int main() {
    testValidBureaucrat();
    testTooHigh();
    testTooLow();
    testAssignment();
    return 0;
}
