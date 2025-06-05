#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        std::vector<int> _store;
    public:
        //CANNONIC
        Span();
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);

        //constructor
        Span(unsigned int N);

        //jobs
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

};
