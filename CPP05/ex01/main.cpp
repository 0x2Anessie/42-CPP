#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat *bureaucrat = NULL;
	Form *form = NULL;

	// ━━━━━━━━━━━━━━━━━━ Valid Grade to sign the form ━━━━━━━━━━━━━━━━━━ //

	std::cout << BOLD << "\nTEST #1:" << GREEN << " Valid grade to sign the form\n" << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Amy Santiago", 1);
		std::cout << BOLD << "Bureaucrat announce : " << RESET << *bureaucrat;
		form = new Form("Form #1", 1, 1);
		std::cout << BOLD << "Form announce : " << RESET << *form;
		std::cout << BOLD << "\n" << bureaucrat->getName() << " tries to sign the form..." << RESET << std::endl;
		bureaucrat->signForm(*form);
		std::cout << BOLD << "Using getIsSigned to confirm Form #1 signed status is: " << GREEN_BOLD << form->getIsSigned()<< "\n" << RESET << std::endl;
		delete bureaucrat;
		delete form;
		bureaucrat = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	//******************************************************************//

	std::cout << BOLD << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
	std::cout << BOLD << "\nTEST #2:" << GREEN << " Valid grade to sign the form\n" << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Charles Boyles", 24);
		std::cout << BOLD << "Bureaucrat announce : " << RESET << *bureaucrat;
		form = new Form("Form #2", 42, 50);
		std::cout << BOLD << "Form announce : " << RESET << *form;
		std::cout << BOLD << "\n" << bureaucrat->getName() << " tries to sign the form..." << RESET << std::endl;
		bureaucrat->signForm(*form);
		std::cout << BOLD << "Using getIsSigned to confirm Form #2 signed status is: " << GREEN_BOLD << form->getIsSigned()<< "\n" << RESET << std::endl;
		delete bureaucrat;
		delete form;
		bureaucrat = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	
	// ━━━━━━━━━━━━━━━━━━ Inalid Grade to sign the form ━━━━━━━━━━━━━━━━━━ //

	std::cout << BOLD << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
	std::cout << BOLD << "\nTEST #3:" << RED << " Grade too low to sign the form\n" << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jake Peralta", 100);
		std::cout << BOLD << "Bureaucrat announce : " << RESET << *bureaucrat;
		form = new Form("Form #3", 99, 101);
		std::cout << BOLD << "Form announce : " << RESET << *form;
		std::cout << BOLD << "\n" << bureaucrat->getName() << " tries to sign the form..." << RESET << std::endl;
		bureaucrat->signForm(*form);
		std::cout << BOLD << "Using getIsSigned to confirm Form #3 signed status is: " << RED_BOLD << form->getIsSigned()<< "\n" << RESET << std::endl;
		delete bureaucrat;
		delete form;
		bureaucrat = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
}

