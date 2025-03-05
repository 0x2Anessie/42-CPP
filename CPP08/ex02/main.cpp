#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\033c";

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST DE 42 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

		std::cout << GREEN_BOLD << "42 test" << RESET << " : we create a Mutant Stack and add some values\n" << std::endl;

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

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST COMPARE LIST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << GREEN_BOLD << "List test" << RESET << " : we use std::list to compare with MutantStack, \n	    the output should be the same\n" << std::endl;
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

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST POP FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << GREEN_BOLD << "Top of the stack test" << RESET << " : as we add values to the stack, \n			we use top() to get the top value and pop to erase it.\n" << std::endl;
	{
		MutantStack<int> mstack2;
		mstack2.push(1);
		std::cout << GREEN << "adding 1 to stack..." << RESET << std::endl;
		std::cout << BOLD << "Top of stack = " << RESET << mstack2.top() << std::endl;
		mstack2.push(2);
		std::cout << GREEN << "adding 2 to stack..." << RESET << std::endl;
		std::cout << BOLD << "Top of stack = " << RESET << mstack2.top() << std::endl;
		mstack2.push(3);
		std::cout << GREEN << "adding 3 to stack..." << RESET << std::endl;
		std::cout << BOLD << "Top of stack = " << RESET << mstack2.top() << std::endl;
		mstack2.pop();
		std::cout << GREEN << "poping top of stack..." << RESET << std::endl;
		std::cout << BOLD << "Top of stack = " << RESET << mstack2.top() << std::endl;
		mstack2.pop();
		std::cout << GREEN << "poping top of stack..." << RESET << std::endl;
		std::cout << BOLD << "Top of stack = " << RESET << mstack2.top() << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST INCREMENTATION ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

		mstack2.push(10);
		mstack2.push(20);
		mstack2.push(30);
		mstack2.push(40);
		mstack2.push(50);
		mstack2.push(60);
		mstack2.push(70);
		mstack2.push(80);
		mstack2.push(90);
		mstack2.push(100);
		MutantStack<int>::iterator it = mstack2.begin();
		MutantStack<int>::iterator ite = mstack2.end();

		std::cout << std::endl << GREEN_BOLD << "Increment test" << RESET << " : we use an iterator to increment through the stack\n" << std::endl;
		while (it != ite)
		{
			std::cout << BOLD << "Value of *it: " << RESET << *it << std::endl;
			it++;
		}

		// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

		std::cout << std::endl << GREEN_BOLD << "Decrement test" << RESET << " : we use an iterator to decrement through the stack\n" << std::endl;
		while(it != mstack2.begin())
		{
			it--;
			std::cout << BOLD << "Value of *it: " << RESET << *it << std::endl;
		}

		// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

		std::cout << std::endl << GREEN_BOLD << "Reverse increment test" << RESET << " : we use an iterator to reverse increment through the stack\n" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack2.rend();
		while (rit != rite)
		{
			std::cout << BOLD << "Value of *rit: " << RESET << *rit << std::endl;
			rit++;
		}
		std::cout << std::endl;
	}

	return 0;
}
