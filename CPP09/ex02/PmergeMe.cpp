#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(int ac, char **av)
{
	m_size = 0;
	for(int i = 1; i < ac; i++)
	{
		std::stringstream tokens(av[i]);
		std::string token;
		while(tokens >> token)
		{
			char *end;
			int value = strtod(token.c_str(), &end);
			if(*end != 0)
				throw(std::runtime_error("Invalid argument"));
			else if(value <= 0)
				throw(std::runtime_error("Bad value"));
			m_vector.push_back(value);
			m_deque.push_back(value);
			m_size++;
		}
	}
}

void printVector(const std::vector<double> &m_vector)
{
	std::cout << CYAN << "Vector: " << RESET;
	for (std::vector<double>::const_iterator it = m_vector.begin(); it != m_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


void printDeque(const std::deque<double> &m_deque)
{
	std::cout << YELLOW "Deque: " << RESET;
	for (std::deque<double>::const_iterator it = m_deque.begin(); it != m_deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void vectorBinaryInsert(std::vector<double> &m_vector, double value)
{
	int left = 0;
	int right = m_vector.size() - 1;
	int mid = 0;

	if(value)
	{
		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if(value < m_vector[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		m_vector.insert(m_vector.begin() + left, value);
	}
}

void dequeBinaryInsert(std::deque<double> &m_deque, double value)
{
	int left = 0;
	int right = m_deque.size() - 1;
	int mid = 0;

	if (value)
	{
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (value < m_deque[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		m_deque.insert(m_deque.begin() + left, value);
	}
}

void getJacobVector(std::vector<double> &jacobsthalVec)
{
	jacobsthalVec.push_back(0);
	jacobsthalVec.push_back(2);
	jacobsthalVec.push_back(4);
	jacobsthalVec.push_back(10);
	jacobsthalVec.push_back(20);
	jacobsthalVec.push_back(42);
	jacobsthalVec.push_back(84);
	jacobsthalVec.push_back(170);
	jacobsthalVec.push_back(340);
	jacobsthalVec.push_back(682);
	jacobsthalVec.push_back(1364);
	jacobsthalVec.push_back(2730);
	jacobsthalVec.push_back(5460);
	jacobsthalVec.push_back(10922);
	jacobsthalVec.push_back(21844);
	jacobsthalVec.push_back(43690);
	jacobsthalVec.push_back(87380);
	jacobsthalVec.push_back(174762);
	jacobsthalVec.push_back(349524);
	jacobsthalVec.push_back(699050);
	jacobsthalVec.push_back(1398100);
	jacobsthalVec.push_back(2796202);
	jacobsthalVec.push_back(5592404);
	jacobsthalVec.push_back(11184810);
	jacobsthalVec.push_back(22369620);
	jacobsthalVec.push_back(44739242);
	jacobsthalVec.push_back(89478484);
	jacobsthalVec.push_back(178956970);
	jacobsthalVec.push_back(357913940);
	jacobsthalVec.push_back(715827882);
	jacobsthalVec.push_back(1431655764);
	jacobsthalVec.push_back(2147483647);
}

void sortVector(std::vector<double> &container)
{
	if (container.size() < 1)
	{
		throw(std::runtime_error("error: empty: cannot sort containers"));
	}
	std::vector<double> pairs;
	for (size_t i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	if (container.size() > 2)
	{
		for (size_t i = 1; i < container.size(); i += 2)
			pairs.push_back(container[i]);
		//std::cout << "pairs: ";
		//printVector(pairs);
		sortVector(pairs);
		std::vector<double> main = pairs;
		//std::cout << "main init: ";
		//printVector(main);
		std::vector<double> pending;
		for (size_t i = 0; i < container.size(); i += 2)
			pending.push_back(container[i]);
		//std::cout << "pending: ";
		//printVector(pending);
		std::vector<double> jacobsthalVec;
		getJacobVector(jacobsthalVec);
		for (size_t index = 0; index < pending.size(); index++)
		{
			int j = 0;
			int jacobIndex;
			while (index > jacobsthalVec[j])
				j++;
			if (j != 0)
			{
				//std::cout << "index: " << index << " jacobsthalVec[j]: " << jacobsthalVec[j] << " jacobsthalVec[j - 1]: "<< jacobsthalVec[j - 1] << std::endl;
				//std::cout << YELLOW << "pending.size() - 1: " << pending.size() - 1 << RESET << std::endl;
				if (pending.size() - 1 <= jacobsthalVec[j])
				{
					jacobIndex = pending.size() - (index - jacobsthalVec[j - 1]);
					//std::cout << RED << "jacobIndex: " << jacobIndex << RESET << std::endl;
				}
				else
				{
					jacobIndex = jacobsthalVec[j] + 1 - (index - jacobsthalVec[j - 1]);
					//std::cout << GREEN << "jacobIndex: " << jacobIndex << RESET << std::endl;
				}
			}
			else
				jacobIndex = 0;
			vectorBinaryInsert(main, pending[jacobIndex]);
			//std::cout << "main insert: ";
			//printVector(main);
			container = main;
		}
	}
}

void sortDeque(std::deque<double> &container)
{
	if (container.size() < 1)
	{
		throw(std::runtime_error("error: empty: cannot sort containers"));
	}
	std::deque<double> pairs;
	for (size_t i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	if (container.size() > 2)
	{
		for (size_t i = 1; i < container.size(); i += 2)
			pairs.push_back(container[i]);
		sortDeque(pairs);
		std::deque<double> main = pairs;
		std::deque<double> pending;
		for (size_t i = 0; i < container.size(); i += 2)
			pending.push_back(container[i]);
		std::vector<double> jacobsthalVec;
		getJacobVector(jacobsthalVec);
		for (size_t index = 0; index < pending.size(); index++)
		{
			int j = 0;
			int jacobIndex;
			while (index > jacobsthalVec[j])
				j++;
			if (j != 0)
			{
				if (pending.size() - 1 <= jacobsthalVec[j])
					jacobIndex = pending.size() - (index - jacobsthalVec[j - 1]);
				else
					jacobIndex = jacobsthalVec[j] + 1 - (index - jacobsthalVec[j - 1]);
			}
			else
				jacobIndex = 0;
			dequeBinaryInsert(main, pending[jacobIndex]);
			container = main;
		}
	}
}


void PmergeMe::merge()
{

	std::cout << YELLOW << BOLD << "[Deque]" << std::endl << " Before: " << RESET;
	printDeque(m_deque);
	clock_t startDeque = clock();
	sortDeque(m_deque);
	clock_t endDeque = clock();
	double timeDeque = ((double)(endDeque - startDeque) / CLOCKS_PER_SEC) * 1000;
	std::cout << YELLOW << BOLD << " After:  " << RESET;
	printDeque(m_deque);
	std::cout << YELLOW << BOLD "Time to sort " << m_size << " values with deque : " << timeDeque << " us" << RESET << std::endl;

	std::cout << CYAN << BOLD << "[Vector]" << std::endl << " Before: " << RESET;
	printVector(m_vector);
	clock_t startVector = clock();
	sortVector(m_vector);
	clock_t endVector = clock();
	double timeVector = ((double)(endVector - startVector) / CLOCKS_PER_SEC) * 1000;
	std::cout << CYAN << BOLD << " After:  " << RESET;
	printVector(m_vector);
	std::cout << CYAN << BOLD << "Time to sort " << m_size << " values with vector : " << timeVector << " us" << RESET << std::endl;
}
