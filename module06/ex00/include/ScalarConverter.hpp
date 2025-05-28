#pragma once

#include <string>
#include <iostream>
#include <ostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
        ScalarConverter(const ScalarConverter& other);

    public:
        //cannonic
        ~ScalarConverter();

        static void converter(const std::string& literal);
};
