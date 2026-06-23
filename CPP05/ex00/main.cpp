/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:20:11 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 14:15:54 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "============ Invalid grades test =============\n";
	{
		std::cout << "Grade Too High\n";
		try
		{
			Bureaucrat a("Invalid", 0);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Grade Too Low\n";
		try
		{
			Bureaucrat a("Invalid", 151);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "============ Various Tests =============\n";
	{
		try
		{
			Bureaucrat a("Lenny", 1);
			Bureaucrat b("John", 150);
			Bureaucrat c("John Jr.", b.getGrade());
			//John Jr. wants to become as equal Lenny is
			c = a;
			std::cout << c << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			//Lenny thinks he can be grade 0
			Bureaucrat a("Lenny", 0);
			Bureaucrat b("John", 150);
			Bureaucrat c("John Jr.", b.getGrade());
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat a("Lenny", 1);
			Bureaucrat b("John", 150);
			Bureaucrat c("John Jr.", b.getGrade());
			//John wants to prove to John Jr. that he can be better than Lenny
			b.raiseGrade(150);
			c = b;
			std::cout << c << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			//The government sees that John is just a father who wants to his kid to be proud of him and raise John grade as much as possible
			Bureaucrat a("Lenny", 1);
			Bureaucrat b("John", 150);
			b.raiseGrade(149);
			Bureaucrat c("John Jr.", b.getGrade());
			//Lenny cant accept that and tries to become the villain (but he fails)
			a.decGrade(150);
			c = b;
			std::cout << c << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			//Lenny have a kid, and understand John behaviour, so his grade raise a lil bit
			Bureaucrat a("Lenny", 150);
			a.raiseGrade();
			Bureaucrat b("John", 1);
			Bureaucrat c("John Jr.", b.getGrade());
			Bureaucrat d("Lenny Jr.", a.getGrade());
			c = b;
			std::cout << c << std::endl;
			std::cout << d << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
