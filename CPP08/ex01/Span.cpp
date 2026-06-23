/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:52:14 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/23 12:36:20 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): len(0) {}

Span::Span(unsigned int N): len(N) {}

Span::~Span() {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->vec.clear();
		this->vec = other.getVec();
		this->len = other.getLen();
	}
	return *this;
}

void Span::addNumber(unsigned int number)
{
	if (len == this->vec.size())
		throw std::length_error("Span limit reached");
	this->vec.push_back(number);
}

void
Span::addNumber(std::vector<unsigned int>::iterator start,
		std::vector<unsigned int>::iterator end)
{
	if (start < end)
	{
		for(; start != end; start++)
		{
			if (this->len == this->vec.size())
				throw std::length_error("Span limit reached");
			this->vec.push_back(*start);
		}
	}
	else if (start > end)
	{
		throw std::length_error("start larger than end pointer");
	}
}

unsigned int Span::shortestSpan() const
{
	if (this->vec.size() <= 1)
		throw std::length_error("Span too short");

	std::vector<unsigned int> copy = this->vec;

	std::sort(copy.begin(), copy.end());

	return std::abs(static_cast<long>(*(copy.begin()))
						- static_cast<long>(*(copy.begin() + 1)));
}

unsigned int Span::longestSpan() const
{
	if (this->vec.size() <= 1)
		throw std::length_error("Span too short");

	std::vector<unsigned int>::const_iterator min_val = 
		std::min_element(this->vec.begin(), this->vec.end());

	std::vector<unsigned int>::const_iterator max_val = 
		std::max_element(this->vec.begin(), this->vec.end());

	return std::abs(static_cast<long>(*max_val)
						- static_cast<long>(*min_val));
	
}

std::vector<unsigned int> Span::getVec() const
{
	return this->vec;
}

size_t	Span::getLen() const
{
	return this->len;
}
