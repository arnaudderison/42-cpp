#include "Span.hpp"
#include <climits>

int main() {
    Span a(2);

    try{
        int arr[] = {INT_MIN, INT_MAX};

        std::vector<int> v(arr, arr + 2);
        a.addNumbers(v.begin(), v.end());

        std::cout << "longestSpan: "<< a.longestSpan() << std::endl;
        std::cout << "shortestSpan: "<< a.shortestSpan() << std::endl;
        
    } catch(const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    return 0;
}