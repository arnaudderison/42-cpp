#include "Span.hpp"

int main() {
    Span a(5);

    try{
        a.addNumber(1);
        a.addNumber(2);
        a.addNumber(100);
        a.addNumber(8);
        a.addNumber(10);
        // a.addNumber(1);

        std::cout << "longestSpan: "<< a.longestSpan() << std::endl;
        std::cout << "shortestSpan: "<< a.shortestSpan() << std::endl;
        
    } catch(const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    return 0;
}