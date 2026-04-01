/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:02:41 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:39:41 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->brain = new Brain();
	*this = other;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &value)
{
	if (this != &value)
	{
		*this->brain = *value.brain;
		this->type = value.type;
	}
	std::cout << "Dog Copy Assignment operator called" << std::endl;
	return *this;
}

void	Dog::setIdea(int index, std::string &newIdea)
{
	this->brain->setIdeas(index, newIdea);	
}

const std::string Dog::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "Index out of bounds" << std::endl;
		return "";
	}
	return this->brain->getIdeas()[index];
}

const std::string *Dog::getAllIdeas() const
{
	return this->brain->getIdeas();
}

void	Dog::makeSound() const
{
	std::cout << "wuf...wuf..." << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

