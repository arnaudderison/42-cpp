#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"
#include "print_utils.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {
    
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

void ScalarConverter::converter(const std::string& literal) {
    char c;
    int i;
    float f;
    double d;

    switch (detectType(literal))
    {
        case INT:
        case FLOAT:
        case DOUBLE:
            d = std::atof(literal.c_str());
            
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            f = static_cast<float>(d);
            
            print_cast(c, i, f, d, detectType(literal));
            break;
        
        case CHAR:
            c = literal[0];

            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);

            print_cast(c, i, f, d, detectType(literal));    
            break;

        case PSEUDO_LITERAL:
            f = std::atof(literal.c_str());

            i = static_cast<int>(f);
            d = static_cast<double>(f);
            c = static_cast<char>(f);
            print_cast(c, i, f, d, detectType(literal));
            break;
        
        default:
            print_char(0, false);
            print_double(0.0, false);
            print_float(0.0f, false);
            print_int(0, false);
            break;
    }
}
