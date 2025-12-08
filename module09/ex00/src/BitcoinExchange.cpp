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
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
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

    while (std::getline(input, line)) {
        if (line == "date,exchange_rate")
            continue;
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && (iss >> rate))
            _DataBase[date] = rate;
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
    std::size_t pipe;

    if (!input) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    while (std::getline(input, line)) {
        if (line == "date | value" || line.empty())
            continue;

        pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date  = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        if (!isValideDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        std::istringstream iss(valueStr);
        if (!(iss >> value) || !(iss >> std::ws).eof()) {
            std::cout << "Error: bad value" << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = _DataBase.lower_bound(date);
        if (it == _DataBase.end() || it->first != date) {
            if (it == _DataBase.begin()) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }

    input.close();
}
