/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:18:47 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 14:48:33 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): type("")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): type(type)
{
	std::cout << "AMateria Type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other): type(other.getType())
{
	std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &value)
{
	if (this != &value)
	{
		(void)value;
	}
	std::cout << "AMateria Copy Assignment operator called" << std::endl;
	return *this;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default destructor called" << std::endl;
}
