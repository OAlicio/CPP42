/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:24:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/04 12:45:56 by ofeverei         ###   ########.fr       */
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

Fixed::Fixed(const int integer)
{
	this->setRawBits(integer << Fixed::fBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal)
{
	int		scaledVal;

	scaledVal = roundf(floatVal * (1 << Fixed::fBits));
	this->setRawBits(scaledVal);
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
		this->fPointVal = value.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &value) const
{
	if (this->getRawBits() > value.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &value) const
{
	if (this->getRawBits() < value.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &value) const
{
	if (this->getRawBits() >= value.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &value) const
{
	if (this->getRawBits() <= value.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &value) const
{
	if (this->getRawBits() == value.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &value) const
{
	if (this->getRawBits() != value.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &value)
{
	Fixed res;

	res.setRawBits(this->getRawBits() + value.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &value)
{
	Fixed res;

	res.setRawBits(this->getRawBits() - value.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &value)
{
	Fixed	res;

	res.setRawBits((this->getRawBits() * value.getRawBits())/(1 << Fixed::fBits));
	return res;
}

Fixed Fixed::operator/(const Fixed &value)
{
	Fixed ret;

	ret.setRawBits((this->getRawBits() * (1 << Fixed::fBits)) / value.getRawBits());
	return ret;
}

Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	postInc;

	postInc = *this;
	this->setRawBits(this->getRawBits() + 1);
	return postInc;
}

Fixed Fixed::operator--(int)
{
	Fixed	postInc;

	postInc = *this;
	this->setRawBits(this->getRawBits() - 1);
	return postInc;
}

std::ostream& operator<<(std::ostream& os, const Fixed &value)
{
	os << (float) value.getRawBits() / (1 << Fixed::getFBits());
	return os;
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
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
