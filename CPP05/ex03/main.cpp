/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:20:11 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 15:49:47 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	john;
	AForm *robotomyForm = NULL;
	AForm *presidentialForm = NULL;
	AForm *shrubberyForm = NULL;

	std::cout << "====== Robotomy  Request (using dynamic polymorphism) tests    ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			robotomyForm = john.makeForm("robotomy request", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*robotomyForm);
				president.executeForm(*robotomyForm);
				delete robotomyForm;
			}
			catch(std::exception &e)
			{
				delete robotomyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			robotomyForm = john.makeForm("robotomy request", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.executeForm(*robotomyForm);
				delete robotomyForm;
			}
			catch(std::exception &e)
			{
				delete robotomyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			robotomyForm = john.makeForm("robotomy request", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*robotomyForm);
				robotomyForm->beSigned(president);
				president.executeForm(*robotomyForm);
				delete robotomyForm;
			}
			catch(std::exception &e)
			{
				delete robotomyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nInvalid Form Name\n";
		try
		{
			robotomyForm = john.makeForm("robotomy creation", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*robotomyForm);
				robotomyForm->beSigned(president);
				president.executeForm(*robotomyForm);
				delete robotomyForm;
			}
			catch(std::exception &e)
			{
				delete robotomyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n====== Presidential Request (using dynamic polymorphism) tests ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			presidentialForm = john.makeForm("presidential pardon", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*presidentialForm);
				president.executeForm(*presidentialForm);
				delete presidentialForm;
			}
			catch(std::exception &e)
			{
				delete presidentialForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			presidentialForm = john.makeForm("presidential pardon", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.executeForm(*presidentialForm);
				delete presidentialForm;
			}
			catch(std::exception &e)
			{
				delete presidentialForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			presidentialForm = john.makeForm("presidential pardon", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*presidentialForm);
				presidentialForm->beSigned(president);
				president.executeForm(*presidentialForm);
				delete presidentialForm;
			}
			catch(std::exception &e)
			{
				delete presidentialForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nInvalid Form Name\n";
		try
		{
			presidentialForm = john.makeForm("president decret", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*presidentialForm);
				presidentialForm->beSigned(president);
				president.executeForm(*presidentialForm);
				delete presidentialForm;
			}
			catch(std::exception &e)
			{
				delete presidentialForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n====== Shrubbery Request (using dynamic polymorphism) tests    ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			shrubberyForm = john.makeForm("shrubbery creation", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*shrubberyForm);
				president.executeForm(*shrubberyForm);
				delete shrubberyForm;
			}
			catch(std::exception &e)
			{
				delete shrubberyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			shrubberyForm = john.makeForm("shrubbery creation", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.executeForm(*shrubberyForm);
				delete shrubberyForm;
			}
			catch(std::exception &e)
			{
				delete shrubberyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			shrubberyForm = john.makeForm("shrubbery creation", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*shrubberyForm);
				shrubberyForm->beSigned(president);
				president.executeForm(*shrubberyForm);
				delete shrubberyForm;
			}
			catch(std::exception &e)
			{
				delete shrubberyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nInvalid Form Name\n";
		try
		{
			shrubberyForm = john.makeForm("shruberry creation", "Lenny");
			try
			{
				Bureaucrat president("Mr. President", 1);
				president.signForm(*shrubberyForm);
				shrubberyForm->beSigned(president);
				president.executeForm(*shrubberyForm);
				delete shrubberyForm;
			}
			catch(std::exception &e)
			{
				delete shrubberyForm;
				std::cout << e.what() << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
