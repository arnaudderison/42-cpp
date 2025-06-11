#include "Span.hpp"

Span::Span() {}
Span::~Span() {}
Span::Span(const Span& other) {
    this->_store = other._store;
    this->_store.reserve(other._store.capacity());
    this->_store = other._store;
}
Span& Span::operator=(const Span& other) {
    if(this != &other) {
        this->_store.reserve(other._store.capacity());
        this->_store = other._store;
    }
    return *this;
}

Span::Span(unsigned int N) : _store(), _maxSize(N){
    this->_store.reserve(N);
}

void Span::addNumber(int number) {
    if(this->_store.size() == this->_store.capacity())
        throw std::out_of_range("Vector is full");
    this->_store.push_back(number);
}

size_t Span::shortestSpan() const {
    std::vector<int> tmp(this->_store);
    long min;

    if(this->_store.size() <= 1)
        throw std::logic_error("shortestSpan: Only one number in the vector");
    
    std::sort(tmp.begin(), tmp.end());

    min = tmp[1] - tmp[0];
    for(size_t i = 1; i < tmp.size(); i++) {
        if(tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }

    return min;
}

size_t Span::longestSpan() const {
    std::vector<int> tmp(this->_store);

	if (this->_store.size() <= 1)
		throw std::logic_error("shortestSpan: Only one number in the vector");
        
	std::sort(tmp.begin(), tmp.end());

	return tmp[tmp.size() - 1] - tmp[0];
}
