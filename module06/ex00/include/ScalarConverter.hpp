#pragma once

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();

    public:
        //cannonic
        ~ScalarConverter();

        static void converter(std::string literal);
}
