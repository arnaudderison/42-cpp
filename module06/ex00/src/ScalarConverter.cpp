#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"
#include <cstdlib>
#include <limits.h>
#include <cmath>

void print_char(char c, bool isPossible = true) {
    if(!isPossible)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void print_int(int i, bool isPossible = true) {
    if(!isPossible)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: '" << i << "'" << std::endl;
}

void print_float(float f, bool isPossible = true) {
    if(!isPossible)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: '" << f << "f'" << std::endl;
}

void print_double(double d, bool isPossible = true) {
    if(!isPossible)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: '" << d << "'" << std::endl;
}

void print_cast(char c, int i, float f, double d, const std::string& literal) {
    if(!std::isprint(c))
        print_char(c, false);
    else
        print_char(c);
    print_double(d);
    print_float(f);
    if (d > INT_MAX || d < INT_MIN || d != d)
        print_int(i, false);
    else
        print_int(i);
    (void)literal;
}

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {
    
}

void ScalarConverter::converter(const std::string& literal) {
    char c;
    int i;
    float f;
    double d;

    std::cout << detectType(literal) << std::endl;
    switch (detectType(literal))
    {
        case INT:
        case FLOAT:
        case DOUBLE:
            d = std::atof(literal.c_str());
            
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            f = static_cast<float>(d);
            
            print_cast(c, i, f, d, literal);
            break;
        case CHAR:
            c = literal[0];

            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);

            print_cast(c, i, f, d, literal);    
            break;
        case PSEUDO_LITERAL:
            f = std::atof(literal.c_str());

            i = static_cast<int>(f);
            d = static_cast<double>(f);
            c = static_cast<char>(f);
            print_cast(c, i, f, d, literal);
            break;
        
        default:
            print_char(0, false);
            print_double(0.0, false);
            print_float(0.0f, false);
            print_int(0, false);
            break;
    }
}


// //TODO
// - [ ] REFACTORISER SWITCH STATEMENT