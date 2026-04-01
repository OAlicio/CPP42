/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:11:45 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:40:18 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->brain = new Brain();
	*this = other;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &value)
{
	if (this != &value)
	{
		*this->brain = *value.brain;
		this->type = value.type;
	}
	std::cout << "Cat Copy Assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "miauu...miauu..." << std::endl;
}

void	Cat::setIdea(int index, std::string &newIdea)
{
	this->brain->setIdeas(index, newIdea);	
}

const std::string Cat::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "Index out of bounds" << std::endl;
		return "";
	}
	return this->brain->getIdeas()[index];
}

const std::string *Cat::getAllIdeas() const
{
	return this->brain->getIdeas();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}
