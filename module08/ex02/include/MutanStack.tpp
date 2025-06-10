#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
    if (this != &other)
        std::stack<T, Container>::operator=(other);
    return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
    return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
    return this->c.rend();
}
