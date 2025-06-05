#include "easyfind.hpp"
#include <vector>

int main() {

    try{

        int arr[] = {1,2,3,4,5};
        std::vector<int> v(arr, arr + 5);
    
        easyfind(v, 6);
        // std::cout << *test << std::endl;
    } catch(const std::exception& e) {}

    return 0;
}