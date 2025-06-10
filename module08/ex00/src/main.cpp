#include "easyfind.hpp"
#include <vector>

int main() {

    try{

        int arr[] = {1,2,3,4,5};
        std::vector<int> v(arr, arr + 5);
        std::vector<int>::iterator ret;
    
        ret = easyfind(v, 6);
        std::cout << *ret << std::endl;
    } catch(const std::exception& e) {}

    return 0;
}