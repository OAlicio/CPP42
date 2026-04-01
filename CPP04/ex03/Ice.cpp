/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:50:46 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 17:34:54 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(std::string const &type): AMateria("ice")
{
	(void)type;
	std::cout << "Ice Type constructor called" << std::endl;
}

Ice::Ice(const Ice &other): AMateria(other.getType())
{
	*this = other;
	std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &value)
{
	if (this != &value)
	{
		(void)value;
	}
	std::cout << "Ice Copy Assignment operator called" << std::endl;
	return *this;
}

std::string const &Ice::getType() const
{
	return this->type;
}

Ice *Ice::clone() const
{
	return new Ice;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Default destructor called" << std::endl;
}
