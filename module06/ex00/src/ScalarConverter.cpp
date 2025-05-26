#include "ScalarConverter.hpp"

typedef enum e_TypeConvert {
    NAN,
    NANF,
    INFP, //+inf
    INFN, //-inf
    INFFP, //+inff
    INFFN, //-inff
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL
} TypeConvert;

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

static TypeConvert detectType(const std::string& literal) {
    if(isChar(literal)) {
        std::cout << "Type detected: char" << std::endl;
        return CHAR;
    }

    if(isPseudoLiteral(literal)) {
        std::cout << "Type detected: pseudo-literal" << std::endl;
        return PSEUDO_LITERAL;
    }
}