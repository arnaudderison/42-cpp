#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2 || !argv[1]) {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }

    ScalarConverter::converter(argv[1]);
    return 0;
}