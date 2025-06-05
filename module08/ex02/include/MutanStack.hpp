#pragma once

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
    private:
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);

        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();

};

#include "MutanStack.tpp"