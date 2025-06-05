#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array() {
    _data = NULL;
    _size = 0;
}

//Les () garantissent que chaque élément du tableau est initialisé par défaut (0 ou constructeur par défaut).
template<typename T>
Array<T>::Array(unsigned int N) {
    _data = new T[N]();
    _size = N;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        } else
            _data = NULL;
    }
    return *this;
}

template<typename T>
Array<T>::Array(const Array& other) {
    this->_size = other._size;
    if(_size > 0) {
        this->_data = new T[other._size];
        for(unsigned int i = 0; i < _size; i++) {
            this->_data[i] = other._data[i];
        }
    } else
        this->_data = NULL;
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if(index >= _size)
        throw std::out_of_range("index is out of bounds");
    return _data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if(index >= _size)
        throw std::out_of_range("index is out of bounds");
    return _data[index];
}

template<typename T>
Array<T>::~Array() {
    delete[] _data;
}
