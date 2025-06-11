#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        std::vector<int> _store;
        unsigned int _maxSize;
    public:
        //CANNONIC
        Span();
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);

        //constructor
        Span(unsigned int N);

        //jobs
        template<typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            if(_store.size() + std::distance(begin, end) > _store.capacity())
                throw std::out_of_range("The span is full");
            _store.insert(_store.end(), begin, end);
        }
        void addNumber(int number);
        size_t shortestSpan() const;
        size_t longestSpan() const;

};
