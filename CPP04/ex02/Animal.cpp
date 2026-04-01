/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:13:26 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:40:09 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &value)
{
	if (this != &value)
	{
		this->type = value.type;
	}
	std::cout << "Animal Copy Assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

const std::string	&Animal::getType() const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout << "Some animal sound..." << std::endl;
}
