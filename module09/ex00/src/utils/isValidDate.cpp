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
        return false;
    
    strYear = date.substr(0, 4);
    strMonth = date.substr(5, 2);
    strMonth = date.substr(8, 2);

    
    if(!parseInt(strYear, year) || !parseInt(strMonth, month) || !parseInt(strDay, day))
        return false;
    if(month > 12 || month <= 1 || day < 1)
        return false;
    
    if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;
        
    return day <= daysInMonth[month - 1];
}
