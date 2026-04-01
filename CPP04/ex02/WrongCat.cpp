/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:14:45 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:40:37 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->brain = new Brain();
	this->type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->brain = new Brain();
	*this = other;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &value)
{
	if (this != &value)
	{
		*this->brain = *value.brain;
		this->type = value.type;
	}
	std::cout << "WrongCat Copy Assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "miauu...miauu..." << std::endl;
}

void	WrongCat::setIdea(int index, std::string &newIdea)
{
	this->brain->setIdeas(index, newIdea);	
}

const std::string WrongCat::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "Index out of bounds" << std::endl;
		return "";
	}
	return this->brain->getIdeas()[index];
}

const std::string *WrongCat::getAllIdeas() const
{
	return this->brain->getIdeas();
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << "WrongCat Destructor called" << std::endl;
}
