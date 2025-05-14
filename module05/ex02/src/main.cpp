#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Color.hpp"


int main() {
    try {
        Bureaucrat aderison("aderison", 150);
        ShrubberyCreationForm form("test");

        std::cout << aderison << std::endl;
        std::cout << form << std::endl;

        aderison.signForm(form);
        aderison.executeForm(form);
    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
