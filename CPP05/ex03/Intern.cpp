/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:58:37 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 15:20:57 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{}
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Intern Couldn't Find the Form";
}

AForm *Intern::createPresidentialPardonForm(std::string formTarget)
{
	return new PresidentialPardonForm(formTarget);
}

AForm *Intern::createRobotomyRequestForm(std::string formTarget)
{
	return new RobotomyRequestForm(formTarget);
}

AForm *Intern::createShrubberyCreationForm(std::string formTarget)
{
	return new ShrubberyCreationForm(formTarget);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	size_t i = 0;
	AForm *fform = NULL;
	const std::string forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm *(Intern::*form[3])(std::string)=
	{
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};

	for (; i < 3; i++)
	{
		if (!forms[i].compare(formName))
		{
			fform = (this->*form[i])(formTarget);
			std::cout << "Intern creates " << fform->getName() << std::endl;
			return fform;
		}
	}
	throw FormNotFoundException();
}
