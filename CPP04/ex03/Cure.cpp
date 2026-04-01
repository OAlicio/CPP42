/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:50:01 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 17:34:27 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(std::string const &type): AMateria("cure")
{
	(void)type;
	std::cout << "Cure Type constructor called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria("cure")
{
	*this = other;
	std::cout << "Cure Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &value)
{
	if (this != &value)
	{
		(void)value;
	}
	std::cout << "Cure Copy Assignment operator called" << std::endl;
	return *this;
}

std::string const &Cure::getType() const
{
	return this->type;
}

Cure *Cure::clone() const
{
	return new Cure;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Default destructor called" << std::endl;
}
