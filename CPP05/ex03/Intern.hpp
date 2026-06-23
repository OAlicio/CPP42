/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:55:53 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/25 15:20:59 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string formName, std::string formTarget);
		AForm *createPresidentialPardonForm(std::string formTarget);
		AForm *createRobotomyRequestForm(std::string formTarget);
		AForm *createShrubberyCreationForm(std::string formTarget);
		class FormNotFoundException : public std::exception
		{
			public:
				const  char *what() const throw();
		};
};

#endif
