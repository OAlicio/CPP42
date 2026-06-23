/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:53:27 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/29 12:03:52 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	Data::ids = 0;

Data::Data() : id(ids), type(""), content("")
{
	Data::ids++;
} 

Data::Data(const std::string &type, const std::string &content) : id(ids), type(type), content(content)
{
	Data::ids++;
} 

Data::Data(const Data &other) : id(ids), type(other.getType()), content(other.getContent())
{
	Data::ids++;
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->content = other.getContent();
		this->type = other.getType();
	}
	return *this;
}

std::string Data::getType() const
{
	return this->type;
}

int Data::getId() const
{
	return this->id;
}

std::string Data::getContent() const
{
	return this->content;
}
