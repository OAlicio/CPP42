/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:20:11 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 14:17:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=============== Invalid Creation Tests ===============\n\n";
	{
		std::cout << "Invalid Sign Grade Too High\n";
		try
		{
			Form form("Invalid Form", 0, 1);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Invalid Sign Grade Too Low\n";
		try
		{
			Form form("Invalid Form", 151, 1);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Invalid Execute Grade Too High\n";
		try
		{
			Form form("Invalid Form", 1, 0);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Invalid Execute Grade Too Low\n";
		try
		{
			Form form("Invalid Form", 1, 151);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n=============== Sign Form method Tests ===============\n\n";
	{
		//Lenny's kid told him that school is a bad thing, so he tries to sign a Form that he cant
		try
		{
			Form form("No School Form", 1, 1);
			Bureaucrat bureaucrat("Lenny", 149);
			bureaucrat.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form form("No School Form", 1, 1);
			Bureaucrat bureaucrat("Lenny", 149);
			form.beSigned(bureaucrat);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		//John sees what Lenny attempt to, and realize his son enjoy, so he sign a form for more schools
		try
		{
			Form form("More School Form", 125, 15);
			Bureaucrat bureaucrat("John", 4);
			form.beSigned(bureaucrat);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form form("More School Form", 125, 15);
			Bureaucrat bureaucrat("John", 4);
			bureaucrat.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "================= Assignment operator and Copy Constructor Test (Form Class) =================\n\n";
			std::cout << "\n";
			Bureaucrat president("Mr. President", 1);
			Form form1("More School Form", 125, 15);
			std::cout << "Form 1 sign before: " << form1.isSigned() << std::endl;
			president.signForm(form1);
			std::cout << "Form 1 sign after: " << form1.isSigned() << std::endl;
			std::cout << "\n";
			Form form2 = form1;
			std::cout << "Form 2 sign before: " << form2.isSigned() << std::endl;
			president.signForm(form2);
			std::cout << "Form 2 sign after: " << form2.isSigned() << std::endl;
			std::cout << "\n";
			Form form3("", 150, 150);
			std::cout << "Form 3 sign before: " << form3.isSigned() << std::endl;
			form3 = form1;
			std::cout << "Form 3 sign before: " << form3.isSigned() << std::endl;
			president.signForm(form3);
			std::cout << "Form 3 sign after: " << form3.isSigned() << std::endl;
			std::cout << "\n";
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
