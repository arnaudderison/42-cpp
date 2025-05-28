#include <iostream>
#include "iter.hpp"

template<typename T>
void printElement(T const &elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void incrementElement(T &elem) {
    elem++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array:" << std::endl;
    iter(arr, len, printElement<int>);

    std::cout << "Incrementing array..." << std::endl;
    iter(arr, len, incrementElement<int>);

    std::cout << "Array after increment:" << std::endl;
    iter(arr, len, printElement<int>);

    std::string sarr[] = {"hello", "world", "!"};
    len = sizeof(sarr) / sizeof(sarr[0]);

    std::cout << "String array:" << std::endl;
    iter(sarr, len, printElement<std::string>);

    return 0;
}
