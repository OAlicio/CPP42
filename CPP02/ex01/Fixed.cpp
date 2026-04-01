/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:24:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/03 16:26:45 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fPointVal = 0;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed& Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
	{
		this->fPointVal = value.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed &value)
{
	os << (float) value.getRawBits() / (1 << Fixed::getFBits());
	return os;
}

Fixed::Fixed(const int integer)
{
	this->setRawBits(integer << Fixed::fBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal)
{
	int		intVal;

	intVal = roundf(floatVal * (1 << Fixed::fBits));
	this->setRawBits(intVal);
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::getFBits()
{
	return Fixed::fBits;
}

int	Fixed::getRawBits() const
{
	return this->fPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	this->fPointVal = raw;
}

float	Fixed::toFloat(void) const
{
	float	res;

	res = (float) this->getRawBits() / (1 << Fixed::fBits); 	
	return res;
}

int		Fixed::toInt(void) const
{
	int res;

	res = this->getRawBits() / (1 << Fixed::fBits); 
	return res;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
