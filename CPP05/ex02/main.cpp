/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:20:11 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 15:28:23 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm *robotomyForm = NULL;
	AForm *presidentialForm = NULL;
	AForm *shrubberyForm = NULL;

	std::cout << "====== Robotomy  Request (using dynamic polymorphism) tests    ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			robotomyForm = new RobotomyRequestForm("Lenny");
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
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			robotomyForm = new RobotomyRequestForm("Lenny");
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
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			robotomyForm = new RobotomyRequestForm("Lenny");
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

	std::cout << "\n====== Presidential Request (using dynamic polymorphism) tests ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			presidentialForm = new PresidentialPardonForm("Lenny");
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
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			presidentialForm = new PresidentialPardonForm("Lenny");
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
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			presidentialForm = new PresidentialPardonForm("Lenny");
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

	std::cout << "\n====== Shrubbery Request (using dynamic polymorphism) tests    ======\n\n";
	{
		std::cout << "Signed Form been executed\n";
		try
		{
			shrubberyForm = new ShrubberyCreationForm("Lenny");
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
	{
		std::cout << "\nUnsigned Form been executed\n";
		try
		{
			shrubberyForm = new ShrubberyCreationForm("Lenny");
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
	{
		std::cout << "\nDouble Signed Form been executed\n";
		try
		{
			shrubberyForm = new ShrubberyCreationForm("Lenny");
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
}
