#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main() {
    Data* data = new Data();
    Data* decrypt;

    data->data = 42;
    data->name = "test";

    std::cout << "data data : "<< data->data << " data name: " << data->name << std::endl; 

    uintptr_t serialized = Serializer::serialize(data);
    decrypt = Serializer::deserialize(serialized);

    std::cout << "decrypt data : "<< decrypt->data << " decrypt name: " << decrypt->name << std::endl; 

    delete data;
    return 0;
}