/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:49:52 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/23 12:42:29 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(200000);
	Span oth = sp;
	std::vector<unsigned int> arr;
	for (size_t i = 0; i < 200000; i++)
		arr.push_back(i);
	sp.addNumber(arr.begin(), arr.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	oth.addNumber(2001);
	std::cout << "Try to add more number than the expected\n";
	try
	{
		sp.addNumber(2001);
	}
	catch(std::length_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
