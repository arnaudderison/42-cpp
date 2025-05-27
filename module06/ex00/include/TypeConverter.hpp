#pragma once

#include <string>

typedef enum e_TypeConvert {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    INVALID
} TypeConvert;

TypeConvert detectType(const std::string& literal);