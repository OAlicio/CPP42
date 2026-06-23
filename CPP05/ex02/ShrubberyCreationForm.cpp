/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:54:57 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 14:09:13 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137), target("Default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream outFile;

	if (!isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	outFile.open((target + "_shrubbery").c_str());
	if (!outFile.is_open()) //Maybe throw an error??
	{
		std::cerr << "Error while creating output file\n";
		return;
	}
	outFile <<
   "	 *                 @@@@@     \n\
        ***              @@@@@@@@@   \n\
       *****            @@@@@@@@@@@  \n\
      *******          @@@@@@@@@@@@@ \n\
     *********          @@@@@@@@@@@  \n\
    ***********           @@@@@@@    \n\
        |||                 |||      \n\
        |||                 |||      \n\
                            ___      \n";
	outFile.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}


