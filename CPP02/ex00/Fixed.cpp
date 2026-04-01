/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:24:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/02 15:47:55 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fPointVal = 0;
}

Fixed::Fixed(Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed& Fixed::operator=(Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
	{
		this->fPointVal = value.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	this->fPointVal = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
