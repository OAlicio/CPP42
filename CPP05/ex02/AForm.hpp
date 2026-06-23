/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:28:54 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/21 11:46:31 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		virtual AForm &operator=(const AForm &other);
		virtual ~AForm() = 0;
		bool				isSigned() const;
		const int			&getGradeToSign() const;
		const int			&getGradeToExecute() const;
		const std::string	&getName() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);

#endif
