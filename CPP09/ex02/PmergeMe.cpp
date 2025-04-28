#include "PmergeMe.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS INIT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PMERGEME FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// parse les arguments de la ligne de commande et les stocke dans les containers
PmergeMe::PmergeMe(int ac, char **av)
{
	containerSize = 0;

	for(int i = 1; i < ac; i++)
	{
		std::stringstream tokens(av[i]);
		std::string token;

		while(tokens >> token)
		{
			char *end;
			int value = strtod(token.c_str(), &end); // convertit le token en nombre

			if(*end != 0) // check si le token est un nombre
				throw(std::runtime_error("You must enter only numbers"));

			else if(value <= 0) // check si le nombre est positif
				throw(std::runtime_error("You must enter only positive numbers"));

			// si les tokens sont valides, on stocke dans les containers
			vectorContainer.push_back(value);
			dequeContainer.push_back(value);
			containerSize++;
		}
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ JACOBSTHAL VECTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SORT FT FOR VECTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void vectorBinaryInsert(std::vector<double> &vectorContainer, double value)
{
	int left = 0;
	int right = vectorContainer.size() - 1;
	int mid = 0;
	
	if(value)
	{
		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if(value < vectorContainer[mid])
			right = mid - 1;
			else
				left = mid + 1;
			}
		vectorContainer.insert(vectorContainer.begin() + left, value);
	}
}

void sortVector(std::vector<double> &container)
{
	if (container.size() < 1)
		throw(std::runtime_error("error: empty: cannot sort containers"));
	
	std::vector<double> pairs;
	for (size_t i = 0; i < container.size() - 1; i += 2) // on se balade dans le tableau de paire en paire
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]); // on met le plus petit en premier
	
	if (container.size() > 2)
	{
		for (size_t i = 1; i < container.size(); i += 2)
			pairs.push_back(container[i]);

		sortVector(pairs);
		std::vector<double> main = pairs;

		std::vector<double> pending;
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

			vectorBinaryInsert(main, pending[jacobIndex]);
			container = main;
		}
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SORT FT FOR DEQUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void dequeBinaryInsert(std::deque<double> &dequeContainer, double value)
{
	int left = 0;
	int right = dequeContainer.size() - 1;
	int mid = 0;

	if (value)
	{
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (value < dequeContainer[mid])
				right = mid - 1;
				else
				left = mid + 1;
			}
		dequeContainer.insert(dequeContainer.begin() + left, value);
	}
}

void sortDeque(std::deque<double> &container)
{
	if (container.size() < 1)
		throw(std::runtime_error("error: empty: cannot sort containers"));

	std::deque<double> pairs;
	for (size_t i = 0; i < container.size() - 1; i += 2) // on se balade dans le tableau de paire en paire
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]); // on met le plus petit en premier

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
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MERGE FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void PmergeMe::merge()
{
	std::cout << BOLD << "USING MERGE-INSERTION SORTING ALGORITHM WITH TWO DIFFERENT CONTAINERS\n" << RESET << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ vector ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	std::cout << BLUE << BOLD << "VECTOR CONTAINER" << std::endl << " Before: " << RESET;
	printVectorContent(vectorContainer); // print le contenu du conteneur avant le tri

	clock_t startVector = clock(); // démarre le chrono

	sortVector(vectorContainer); // appel de la fonction de tri

	clock_t endVector = clock(); // arrête le chrono
	double timeVector = ((double)(endVector - startVector) / CLOCKS_PER_SEC) * 1000; // calcule le temps d'exécution

	std::cout << BLUE << BOLD << " After:  " << RESET;
	printVectorContent(vectorContainer); // print le contenu du conteneur après le tri

	// print le temps d'exécution
	std::cout << BLUE << BOLD << "Time to sort " << containerSize << " values with vector : " << timeVector << " us" << RESET << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ deque ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	std::cout << MAGENTA << BOLD << "\nDEQUE CONTAINER" << std::endl << " Before: " << RESET;
	printDequeContent(dequeContainer);
	clock_t startDeque = clock();
	sortDeque(dequeContainer);
	clock_t endDeque = clock();
	double timeDeque = ((double)(endDeque - startDeque) / CLOCKS_PER_SEC) * 1000;
	std::cout << MAGENTA << BOLD << " After:  " << RESET;
	printDequeContent(dequeContainer);
	std::cout << MAGENTA << BOLD "Time to sort " << containerSize << " values with deque : " << timeDeque << " us" << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PRINT FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// va print le contenu du conteneur vector au moment de l'appel
void printVectorContent(const std::vector<double> &vectorContainer)
{
	for (std::vector<double>::const_iterator it = vectorContainer.begin(); it != vectorContainer.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
	
// va print le contenu du conteneur deque au moment de l'appel
void printDequeContent(const std::deque<double> &dequeContainer)
{
	for (std::deque<double>::const_iterator it = dequeContainer.begin(); it != dequeContainer.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}