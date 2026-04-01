/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:40:09 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/17 10:49:09 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &value)
{
	if (this != &value)
	{
		const std::string *otherIdeas = value.getIdeas();
		for (int i = 0; i < 100; i++)
			this->ideas[i] = otherIdeas[i];
	}
	std::cout << "Brain Copy Assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdeas(int index, std::string &idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "index out of bounds" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

const std::string *Brain::getIdeas() const
{
	return this->ideas;
}
