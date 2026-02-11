#pragma once
#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    static void run(int ac, char **av);
    static std::vector<int> sortVector(const std::vector<int>& input);
    static std::deque<int>  sortDeque(const std::deque<int>& input);


private:
    static int parsePositiveInt(const std::string& s);
};
