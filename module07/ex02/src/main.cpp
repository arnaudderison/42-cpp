#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        std::cout << "===========INT===========" << std::endl;
        Array<int> a;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++) {
            b[i] = i * 10;
        }

        Array<int> c(b);
        c[0] = 42;

        Array<int> d;
        d = b;

        std::cout << "b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\nc: ";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << "\nd: ";
        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
        std::cout << std::endl;

        // Test de l'exception
        std::cout << b[10] << std::endl;
        // std::cout << b[-2] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    try {
        std::cout << "===========STRING===========" << std::endl;
        Array<std::string> str(5);
        for (unsigned int i = 0; i < str.size(); i++) {
            str[i] = "test";
        }

        for (unsigned int i = 0; i < str.size(); i++) {
            std::cout << i << ": " << str[i] << std::endl;
        }

        std::cout << str[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
}
