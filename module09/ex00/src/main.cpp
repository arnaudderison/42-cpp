#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    BitcoinExchange btc;

    if(argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        btc.loadDatabase("./assets/data.csv");
        btc.parseInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

/* TODO
    create an class BitcoinExchange
*/