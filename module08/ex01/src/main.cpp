#include "Span.hpp"
#include <climits>

int main() {
    Span a(3);

    try{
        int arr[] = {-15, -18, 0};

        std::vector<int> v(arr, arr + 3);
        a.addNumbers(v.begin(), v.end());

        std::cout << "longestSpan: "<< a.longestSpan() << std::endl;
        std::cout << "shortestSpan: "<< a.shortestSpan() << std::endl;
        
    } catch(const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    return 0;
}