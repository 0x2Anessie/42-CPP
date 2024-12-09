#include "Bureaucrat.hpp"
#include "Form.hpp"

#define TEST(expression, message) \
	if (expression) \
		std::cout << GREEN << "Test passed : " << message << RESET << std::endl; \
	else \
		std::cout << RED << "Test failed : " << message << RESET << std::endl;

int main()
{
	Bureaucrat *original = NULL;
	Bureaucrat *original2 = NULL;
	Form *form = NULL;
	Form *copy = NULL;

	std::cout << YELLOW << "Form creation test" << RESET << std::endl;
	try
	{
		form = new Form("Form1", 42, 24);
		std::cout << *form;
		TEST(form->getName() == "Form1", "Form name is ok");
		TEST(form->getGradeToSign() == 42, "Form sign grade is ok");
		TEST(form->getGradeToExecute() == 24, "Form exec grade is ok");
		delete form;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "Copy constructor test" << RESET << std::endl;
	try
	{
		form = new Form("Form1", 42, 24);
		copy = new Form(*form);
		std::cout << *form;
		std::cout << *copy;
		TEST(form->getName() == copy->getName(), "Copy name is ok");
		TEST(form->getGradeToSign() == copy->getGradeToSign(), "Copy sign grade is ok");
		TEST(form->getGradeToExecute() == copy->getGradeToExecute(), "Copy exec grade is ok");
		delete form;
		delete copy;
		form = NULL;
		copy = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "Signed form test" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Antonio", 5);
		form = new Form("Form1", 42, 24);
		std::cout << *original;
		std::cout << *form;
		original->signForm(*form);
		std::cout << *form;
		TEST(form->getIsSigned() == true, "Form is signed");
		delete original;
		delete form;
		original = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "Signed form with too low grade test" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Fernando", 50);
		form = new Form("Form1", 42, 24);
		std::cout << *original;
		std::cout << *form;
		original->signForm(*form);
		std::cout << *form;
		TEST(form->getIsSigned() == false, "Form is not signed");
		delete original;
		delete form;
		original = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "Signed form with 2 bureaucrat test" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Marta", 23);
		original2 = new Bureaucrat("Valentina", 6);
		form = new Form("Form1", 42, 24);
		std::cout << *original;
		std::cout << *original2;
		std::cout << *form;
		original->signForm(*form);
		std::cout << *form;
		original2->signForm(*form);
		TEST(form->getIsSigned() == true, "Form is signed one time");
		delete original;
		delete original2;
		delete form;
		original = NULL;
		original2 = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}
}

