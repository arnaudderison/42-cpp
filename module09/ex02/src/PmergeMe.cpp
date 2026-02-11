#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <cctype>
#include <stdexcept>
#include <ctime>
#include <vector>
#include <deque>
#include <utility>

int PmergeMe::parsePositiveInt(const std::string& s) {
    if (s.empty())
        throw std::runtime_error("empty");

    for (size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            throw std::runtime_error("not digit");
    }

    long long val = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        val = val * 10 + (s[i] - '0');
        if (val > INT_MAX)
            throw std::runtime_error("overflow");
    }

    if (val <= 0)
        throw std::runtime_error("not positive");

    return static_cast<int>(val);
}

static size_t lowerBoundRangeVector(const std::vector<int>& S, size_t lo, size_t hi, int x) {
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (S[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

static void binaryInsertVector(std::vector<int>& S, size_t hi, int x) {
    size_t pos = lowerBoundRangeVector(S, 0, hi, x);
    S.insert(S.begin() + pos, x);
}

static size_t firstIndexOfVector(const std::vector<int>& S, int value) {
    for (size_t i = 0; i < S.size(); ++i)
        if (S[i] == value) return i;
    throw std::runtime_error("big not found");
}

static std::vector< std::pair<int,int> >
makePairsVector(const std::vector<int>& in, bool& hasStraggler, int& straggler) {
    std::vector< std::pair<int,int> > pairs;
    pairs.reserve(in.size() / 2);

    hasStraggler = (in.size() % 2 != 0);
    if (hasStraggler)
        straggler = in.back();

    for (size_t i = 0; i + 1 < in.size(); i += 2) {
        int a = in[i];
        int b = in[i + 1];
        if (a < b) pairs.push_back(std::make_pair(a, b));
        else       pairs.push_back(std::make_pair(b, a));
    }
    return pairs;
}

static std::vector<size_t> jacobsthalOrder(size_t m) {
    std::vector<size_t> order;
    if (m == 0) return order;

    std::vector<bool> used(m, false);

    order.push_back(0);
    used[0] = true;

    if (m > 1) {
        order.push_back(1);
        used[1] = true;
    }

    size_t Jprev = 1;
    size_t Jcurr = 3;

    while (Jcurr < m) {
        size_t start = (Jcurr < (m - 1)) ? Jcurr : (m - 1);

        for (size_t idx = start; idx > Jprev; --idx) {
            if (!used[idx]) {
                order.push_back(idx);
                used[idx] = true;
            }
        }

        size_t Jnext = Jcurr + 2 * Jprev;
        Jprev = Jcurr;
        Jcurr = Jnext;
    }

    for (size_t i = 0; i < m; ++i) {
        if (!used[i]) {
            order.push_back(i);
            used[i] = true;
        }
    }

    return order;
}

static std::vector< std::pair<int,int> >
reorderPairsBySortedBigsVector(const std::vector< std::pair<int,int> >& pairs,
                               const std::vector<int>& sortedBigs) {
    std::vector< std::pair<int,int> > ordered;
    ordered.reserve(pairs.size());

    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < sortedBigs.size(); ++i) {
        int b = sortedBigs[i];
        bool found = false;

        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].second == b) {
                used[j] = true;
                ordered.push_back(pairs[j]);
                found = true;
                break;
            }
        }
        if (!found)
            throw std::runtime_error("pair matching failed");
    }
    return ordered;
}

static std::vector<int> fordJohnsonVector(const std::vector<int>& in) {
    if (in.size() <= 1)
        return in;

    bool hasStraggler = false;
    int straggler = 0;

    std::vector< std::pair<int,int> > pairs = makePairsVector(in, hasStraggler, straggler);

    std::vector<int> bigs;
    bigs.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].second);

    std::vector<int> sortedBigs = fordJohnsonVector(bigs);

    std::vector< std::pair<int,int> > orderedPairs = reorderPairsBySortedBigsVector(pairs, sortedBigs);

    std::vector<int> S;
    S.reserve(in.size());
    for (size_t i = 0; i < orderedPairs.size(); ++i)
        S.push_back(orderedPairs[i].second);

    std::vector<size_t> order = jacobsthalOrder(orderedPairs.size());
    for (size_t k = 0; k < order.size(); ++k) {
        size_t idx = order[k];
        int small = orderedPairs[idx].first;
        int big   = orderedPairs[idx].second;

        size_t posBig = firstIndexOfVector(S, big);
        binaryInsertVector(S, posBig, small);
    }

    if (hasStraggler) {
        size_t pos = lowerBoundRangeVector(S, 0, S.size(), straggler);
        S.insert(S.begin() + pos, straggler);
    }

    return S;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int>& input) {
    return fordJohnsonVector(input);
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int>& input) {
    std::vector<int> tmp;
    tmp.reserve(input.size());
    for (size_t i = 0; i < input.size(); ++i)
        tmp.push_back(input[i]);

    std::vector<int> sorted = fordJohnsonVector(tmp);

    std::deque<int> out;
    for (size_t i = 0; i < sorted.size(); ++i)
        out.push_back(sorted[i]);

    return out;
}

void PmergeMe::run(int ac, char **av) {
    if (ac < 2)
        throw std::runtime_error("no args");

    std::vector<int> v;
    std::deque<int> d;
    v.reserve(ac - 1);

    for (int i = 1; i < ac; ++i) {
        int x = parsePositiveInt(av[i]);
        v.push_back(x);
        d.push_back(x);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    std::vector<int> sortedVec = sortVector(v);
    std::clock_t endVec = std::clock();

    double timeVec = (static_cast<double>(endVec - startVec) * 1000000.0)
                   / static_cast<double>(CLOCKS_PER_SEC);

    std::clock_t startDeq = std::clock();
    std::deque<int> sortedDeq = sortDeque(d);
    std::clock_t endDeq = std::clock();

    double timeDeq = (static_cast<double>(endDeq - startDeq) * 1000000.0)
                   / static_cast<double>(CLOCKS_PER_SEC);

    std::cout << "After: ";
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        std::cout << sortedVec[i];
        if (i + 1 < sortedVec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of "
              << sortedVec.size()
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of "
              << sortedDeq.size()
              << " elements with std::deque : "
              << timeDeq << " us" << std::endl;
}
