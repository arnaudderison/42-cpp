#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    BitcoinExchange btc;

    if(argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    btc.loadDatabase("./assets/data.csv");
    btc.parseInput(argv[1]);
    return 0;
}

/* TODO
    create an class BitcoinExchange
*/