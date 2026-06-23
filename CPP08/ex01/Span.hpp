/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:42:28 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/23 12:25:19 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

class Span
{
	private:
		std::vector<unsigned int> vec;
		size_t len;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(unsigned int number);
		void addNumber(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);
		//void addNumber(unsigned int *start, unsigned int *end); //Range assignemnt like
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		std::vector<unsigned int> getVec() const;
		size_t	getLen() const;
};

#endif
