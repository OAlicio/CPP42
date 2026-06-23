/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:26:01 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 09:44:42 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->~Bureaucrat();
		new (this) Bureaucrat(other);
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::raiseGrade()
{
	if (this->grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::raiseGrade(unsigned int incVal)
{
	if (this->grade - incVal <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= incVal;
}

void	Bureaucrat::decGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void	Bureaucrat::decGrade(unsigned int decVal)
{
	if (this->grade + decVal > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade -= decVal;
}

void	Bureaucrat::signForm(AForm &aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << this->getName() << " signed " << aform.getName() << std::endl; 
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << aform.getName()
			<< " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " can't execute form " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
