#include "Fonction.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
	if(std::rand() % 3 == 0)
	{
		std::cout << BLUE << "A generated" << RESET << std::endl;
		return new A();
	}
	else if(std::rand() % 3 == 1)
	{
		std::cout << YELLOW << "B generated" << RESET << std::endl;
		return new B();
	}
	else
	{
		std::cout << MAGENTA << "C generated" << RESET << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BLUE << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << MAGENTA << "C" << RESET << std::endl;
	else
		std::cerr << RED << "Unknown type" << RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE << "A" << RESET << std::endl;
		return;
	}
	catch(...)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << YELLOW << "B" << RESET << std::endl;
		return;
	}
	catch(...)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << MAGENTA << "C" << RESET << std::endl;
		return;
	}
	catch(...)
	{
		std::cerr << RED << "Unknown type" << RESET << std::endl;
	}
}
