/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:42:10 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/21 12:46:05 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), target("Default target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm("RobotomyRequestForm", 72, 45), target(other.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::srand(time(NULL));
	int rand = std::rand() % 2;
	std::cout << "*Drilling noises* ";
	if (rand == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}


