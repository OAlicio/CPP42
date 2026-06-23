/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:43:46 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/19 17:47:28 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	name("Default"),
	sign(false),
	gradeToSign(150),
	gradeToExecute(150)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
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

Form::Form(const Form &other) :
	name(other.getName()),
	sign(false),
	gradeToSign(other.getGradeToSign()),
	gradeToExecute(other.getGradeToExecute())
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->~Form();
		new (this) Form(other);
	}
	return *this;
}

bool	Form::isSigned() const
{
	return sign;
}

const int	&Form::getGradeToSign() const
{
	return gradeToSign;
}

const int	&Form::getGradeToExecute() const
{
	return gradeToExecute;
}

const std::string &Form::getName() const
{
	return name;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		sign = true;
	else
		throw GradeTooLowException();
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", form condition:\ngrade to sign "
		<< form.getGradeToSign()
		<< "\ngrade to execute " << form.getGradeToExecute()
		<< "\nis signed "<< (form.isSigned() ? "yes" : "no") << std::endl;  
	return os;
}
