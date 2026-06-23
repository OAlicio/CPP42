/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:43:46 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/21 12:18:48 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	name("Default"),
	sign(false),
	gradeToSign(150),
	gradeToExecute(150)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	name(name),
	sign(false),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw GradeTooLowException();
	if (this->getGradeToSign() <= 0 || this->getGradeToExecute() <= 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) :
	name(other.getName()),
	sign(false),
	gradeToSign(other.getGradeToSign()),
	gradeToExecute(other.getGradeToExecute())
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{}
	return *this;
}

bool	AForm::isSigned() const
{
	return sign;
}

const int	&AForm::getGradeToSign() const
{
	return gradeToSign;
}

const int	&AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

const std::string &AForm::getName() const
{
	return name;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned())
		throw AlreadySignedException();
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		sign = true;
	else
		throw GradeTooLowException();
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "The Form is already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "The Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	os << aform.getName() << ", form condition:\ngrade to sign "
		<< aform.getGradeToSign()
		<< "\ngrade to execute " << aform.getGradeToExecute()
		<< "\nis signed "<< (aform.isSigned() ? "yes" : "no") << std::endl;  
	return os;
}
