#include "TypeConverter.hpp"
#include <cctype>
#include <iostream>

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
    if(isChar(literal)) {
        std::cout << "Type detected: char" << std::endl;
        return CHAR;
    }

    if(isPseudoLiteral(literal)) {
        std::cout << "Type detected: pseudo-literal" << std::endl;
        return PSEUDO_LITERAL;
    }

    return isFID(literal);
}