/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:16:10 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/04 16:45:26 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float& x, const float& y): x(x), y(y) {}

Point::Point(const int& x, const int& y): x(x), y(y) {}

Point::Point(const Point& other): x(other.x), y(other.y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Point& Point::operator=(Point const& other)
{
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
