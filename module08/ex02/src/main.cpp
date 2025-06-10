#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "===== INT STACK TEST =====" << std::endl;
        MutantStack<int> mstack;

        std::cout << "add 5 on top" << std::endl;
        mstack.push(5);
        std::cout << "add 17 on top" << std::endl;
        mstack.push(17);
        std::cout << "Top of stack: " << mstack.top() << std::endl;

        std::cout << "remove top" << std::endl;
        mstack.pop();
        std::cout << "size of stack: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Iterating (normal):" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << std::endl;

        std::cout << "Iterating (reverse):" << std::endl;
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
            std::cout << *rit << std::endl;
    }

    {
        std::cout << "\n===== EMPTY STACK TEST =====" << std::endl;
        MutantStack<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;
        std::cout << "Is empty? " << (empty.empty() ? "yes" : "no") << std::endl;
    }

    {
        std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original);
        copy.push(4);

        std::cout << "Original:" << std::endl;
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
            std::cout << *it << std::endl;

        std::cout << "Copy:" << std::endl;
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << std::endl;
    }

    {
        std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
        MutantStack<int> stack1;
        stack1.push(10);
        stack1.push(20);

        MutantStack<int> stack2;
        stack2 = stack1;

        std::cout << "Stack2 after assignment:" << std::endl;
        for (MutantStack<int>::iterator it = stack2.begin(); it != stack2.end(); ++it)
            std::cout << *it << std::endl;
    }

    {
        std::cout << "\n===== STRING STACK TEST =====" << std::endl;
        MutantStack<std::string> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("MutantStack");

        for (MutantStack<std::string>::const_iterator it = strStack.begin(); it != strStack.end(); ++it)
            std::cout << *it << std::endl;
    }

    return 0;
}
