#include "MutanStack.hpp"

int main()
{
    MutantStack<int> mstack;

    std::cout << "add 5 on top" << std::endl;
    mstack.push(5);
    std::cout << "add 17 on top" << std::endl;
    mstack.push(17);

    std::cout << "Top of stack: " << mstack.top() << std::endl;

    std::cout << "remove top" << std::endl;
    mstack.pop();

    std::cout << "size of stack" << mstack.size() << std::endl;

    std::cout << "add 3 on top" << std::endl;
    mstack.push(3);
     std::cout << "add 5 on top" << std::endl;
    mstack.push(5);
     std::cout << "add 737 on top" << std::endl;
    mstack.push(737);
     std::cout << "add 0 on top" << std::endl;
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}