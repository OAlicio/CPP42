/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:14:45 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:38:57 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &value)
{
	if (this != &value)
		this->type = value.type;
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "miauu...miauu..." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}
