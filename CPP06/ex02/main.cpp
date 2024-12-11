#include "Fonction.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::srand(std::time(0));
	for(int i = 0; i < 6; i++)
	{
		Base *base = generate();
		std::cout << "Identifying pointer: ";
		identify(base);
		std::cout << "Identifying reference: ";
		identify(*base);
		delete base;
	}
	return 0;
}