/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:11:45 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:38:12 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &value)
{
	if (this != &value)
		this->type = value.type;
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "miauu...miauu..." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}
