#include "TypeConverter.hpp"
#include "print_utils.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>

/*
 =============================================================
 |                                                           |
 !                       TypeConvert                         |
 |                                                           |
 =============================================================
 */

static bool isChar(const std::string& literal) {
    if(literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    return false;
}

static bool isPseudoLiteral(const std::string& literal) {
    return (
        literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff"
    );
}

static TypeConvert isFID(const std::string& literal) {
    unsigned int dot = 0;
    unsigned int f = 0;

    for(size_t i = 0; i < literal.length(); i++) {
        if(literal[i] == '.')
            dot++;
        if(literal[i] == 'f')
            f++;
    }

    if(dot == 1 && f == 1 && literal[literal.length() - 1] == 'f')
        return FLOAT;
    if(dot == 1 && f == 0)
        return DOUBLE; 

    for(size_t i = 0; i < literal.length(); i++) {
        if(i == 0 && (literal[0] == '-' || literal[0] == '+'))
            continue;
        if(!std::isdigit(literal[i]))
            return INVALID;     
    }

    return INT;
}

TypeConvert detectType(const std::string& literal) {
    if(isChar(literal))
        return CHAR;

    if(isPseudoLiteral(literal))
        return PSEUDO_LITERAL;

    return isFID(literal);
}

/*
=============================================================
 |                                                           |
 !                      PrintUtils                           |
 |                                                           |
 =============================================================
*/

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
        std::cout  << std::fixed << std::setprecision(1) << "float: '" << f << "f'" << std::endl;
}

void print_double(double d, bool isPossible = true) {
    if(!isPossible)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: '" << d << "'" << std::endl;
}

void print_cast(char c, int i, float f, double d, TypeConvert t) {
    if(!std::isprint(c)  && t != PSEUDO_LITERAL)
        std::cout << "char: Non displayable" << std::endl;
    else if (!std::isprint(c) && t == PSEUDO_LITERAL)
        print_char(c, false);
    else
        print_char(c);
    print_double(d);
    print_float(f);
    if (d > INT_MAX || d < INT_MIN || d != d)
        print_int(i, false);
    else
        print_int(i);
}
