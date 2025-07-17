#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <vector>

class BitcoinExchange {
    private:
        std::map<std::string, double> _DataBase;
        void printDataBase(std::map<std::string, double>& Database) const;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void loadDatabase(const std::string& file);
        void parseInput(const std::string& file);
};

// // utils
// bool isValideDate(std::string& date);