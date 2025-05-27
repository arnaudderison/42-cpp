#pragma once

#include <string>
#include <iostream>
#include <ostream>

class ScalarConverter {
    private:
        ScalarConverter();

    public:
        //cannonic
        ~ScalarConverter();

        static void converter(const std::string& literal);
};
