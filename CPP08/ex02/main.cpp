#include "MutantStack.hpp"
#include <list>


int main()
{
	std::cout << YELLOW << "42 test" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
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

	std::cout << std::endl << YELLOW << "List test" << RESET << std::endl;
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}


	std::cout << std::endl << YELLOW << "MutantStack test" << RESET << std::endl;
	{
		MutantStack<int> mstack2;
		mstack2.push(1);
		std::cout << "top of stack = " << mstack2.top() << std::endl;
		mstack2.push(2);
		std::cout << "top of stack = " << mstack2.top() << std::endl;
		mstack2.push(3);
		mstack2.push(4);
		mstack2.push(5);
		std::cout << "top before pop = " << mstack2.top() << std::endl;
		mstack2.pop();
		std::cout << "top after pop = " << mstack2.top() << std::endl;
		mstack2.push(10);
		mstack2.push(20);
		mstack2.push(30);
		mstack2.push(40);

		std::cout << std::endl << YELLOW << "Increment through stack" << RESET << std::endl;
		MutantStack<int>::iterator it = mstack2.begin();
		MutantStack<int>::iterator ite = mstack2.end();
		while (it != ite)
		{
			std::cout << "Value of stack = " << *it << std::endl;
			it++;
		}

		std::cout << std::endl << YELLOW << "Decrement through stack" << RESET << std::endl;
		while(it != mstack2.begin())
		{
			it--;
			std::cout << "Value of stack = " << *it << std::endl;
		}

		std::cout << std::endl << YELLOW << "Reverse increment through stack" << RESET << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack2.rend();
		while (rit != rite)
		{
			std::cout << "Value of stack = " << *rit << std::endl;
			rit++;
		}
	}
	return 0;
}
