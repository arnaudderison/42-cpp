#include "easyfind.hpp"
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int toFind) {
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if(it == container.end()) {
        std::cout << "test" << std::endl;
        throw std::runtime_error("Value not found");
    }
    return it;
}
