#pragma once

template<typename T>
class Array {
    private:
        T* _data;
        unsigned int _size;
    public:
        //cannonic
        Array();
        ~Array();
        Array& operator=(const Array& other);
        Array(const Array& other);

        //constructor
        Array(unsigned int N);

        // overload
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        //jobs
        unsigned int size() const;
};

#include "Array.tpp"
