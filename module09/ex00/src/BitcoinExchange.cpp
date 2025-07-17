#include "BitcoinExchange.hpp"




static bool parseInt(const std::string& str, int& ret) {
    std::istringstream iss(str);
    iss >> ret;

    return  !iss.fail() && iss.eof();
}

bool isValideDate(std::string& date) {
    std::string strYear;
    std::string strMonth;
    std::string strDay;
    int year;
    int month;
    int day;
    int daysInMonth[] = {21,28,31,30,31,30,31,31,30,31,30,31};
    
    if(date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "bad format" << date[4] << date[7] << date.length() << std::endl;
        return false;
    }
    
    strYear = date.substr(0, 4);
    strMonth = date.substr(5, 2);
    strDay = date.substr(8, 2);
    
    if(!parseInt(strYear, year) || !parseInt(strMonth, month) || !parseInt(strDay, day))
        return false;
    if(month > 12 || month < 1 || day < 1)
        return false;
    
    if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;
        
    return day <= daysInMonth[month - 1];
}










BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _DataBase(other._DataBase) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if(this !=  &other) {
        this->_DataBase = other._DataBase;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& file) {
    std::ifstream input(file.c_str());
    std::string line;
    std::string date;
    double rate;

    if(!input)
        throw std::runtime_error("Error: could not open file.");

    if(std::getline(input, line)) {
        if(line != "date,exchange_rate") {
            std::istringstream iss(line);

            if(std::getline(iss, date, ',') && (iss >> rate)) {
                _DataBase[date] = rate;
            }
        }
    }

    while(std::getline(input, line)) {
        std::istringstream iss(line);

        if(std::getline(iss, date, ',') && (iss >> rate)) {
            _DataBase[date] = rate;
        }
    }

    // printDataBase(this->_DataBase);
    input.close();
}

void BitcoinExchange::printDataBase(std::map<std::string, double>& Database) const {
    for(std::map<std::string, double>::const_iterator it = Database.begin(); it != Database.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void BitcoinExchange::parseInput(const std::string& file) {
    std::ifstream input(file.c_str());
    std::string line;
    std::string date;
    double value;

    if(!input)
        throw std::runtime_error("Error: coul not open file.");

    if(std::getline(input, line)) {
        if(line != "date | value") {
            std::istringstream iss(line);

            std::getline(iss, date, '|');
            if (!(iss >> value)) {
                std::cout << "Error: bad value" << std::endl;    
            };
            date.erase(date.find_last_not_of(" \n\r\t") + 1);

            if(!isValideDate(date))
                std::cout << "Error: bad input => " << date << std::endl;
            else
                std::cout << "Date: " << date << " Value: " << value << std::endl;
        }
    }

    while(std::getline(input, line)) {
        std::istringstream iss(line);

        std::getline(iss, date, '|');

        date.erase(date.find_last_not_of(" \n\r\t") + 1);
        if(!isValideDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        if(!(iss >> value)) {
            std::cout << "Error: bad value" << std::endl;
            continue;
        }

        if(value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if(value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        if(!this->_DataBase[date])
            std::cout << "not found" << std::endl;
        std::cout << date << " => " << value << " = " << value * this->_DataBase[date] << std::endl;


    }

    input.close();
}
