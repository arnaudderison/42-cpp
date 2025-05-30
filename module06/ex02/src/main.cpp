#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

static Base* generate(void) {
    switch (rand() % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            std::cerr << "Probleme with random number in 'generate' function" << std::endl;
            return NULL;
    }
}

static void identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "Class A is identified" << std::endl;
    if(dynamic_cast<B*>(p))
        std::cout << "Class B is identified" << std::endl;
    if(dynamic_cast<C*>(p))
        std::cout << "Class C is identified" << std::endl;
    return ;
}

static void identify(Base &p)
{
        try
        {
                A &a = dynamic_cast<A&>(p);
                (void)a;
                std::cout << "Class A is identified" << std::endl;
        }
        catch (std::exception &e) {}
        try
        {
                B &b = dynamic_cast<B&>(p);
                (void)b;
                std::cout << "Class B is identified" << std::endl;
        }
        catch (std::exception &e) {}
        try
        {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "Class C is identified" << std::endl;
        }
        catch (std::exception &e) {}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}
