#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
    try {
        PmergeMe::run(ac, av);
    } catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
