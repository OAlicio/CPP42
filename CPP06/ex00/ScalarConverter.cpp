/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:05:21 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 17:09:08 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "helper.h"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string &toConvert)
{
	char type = 0;
	size_t	i = 0;
	bool error = false;
	bool isDecimal = false;

	const std::string value = trim(toConvert);
	if (value.empty())
	{
		std::cerr << "Error\nInvalid input: \'" << toConvert << "\'" << std::endl;
		return ;
	}
	if (value[0] == '+' || value[0] == '-')
		i++;
	if (value[0] == '\'')
	{
		if (value.length() == 3)
		{
			type = 'c';
		}
		else
			error = true;
	}
	else if (value == "+inf" || value == "-inf" || value == "inf" || value == "nan"
	|| value == "+inff" || value == "-inff" || value == "inff" || value == "nanf")
		type = 's';
	else
	{
		for (; i < value.size(); i++)
		{
			if (value[i] == '.' && i != 0 && value[i + 1])
			{
				if (isDecimal)
				{
					error = true;
					break ;
				}
				isDecimal = true;
			}
			else if (!std::isdigit(value[i]))
			{
				if (value[i] != 'f')
					error = true;
				break ;
			}
		}
		if (i < 1 && (value[0] == '+' || value[0] == '-'))
			error = true;
		if (value[i] == 'f')
		{
			if (i + 1 == value.size() && isDecimal)
				type = 'f';
			else 
				error = true;
		}
		else if (isDecimal && type != 'f')
			type = 'd';
		else
			type = 'i';
	}

	if (error)
		std::cerr << "Error\nInvalid input: \'" << toConvert << "\'" << std::endl;
	else
		switch(type)
		{
			case 'f':
				convertBasef(value);
				break;
			case 'd':
				convertBased(value);
				break;
			case 's':
				convertBased(value);
				break;
			case 'i':
				convertBasei(value);
				break;
			case 'c':
				convertBasec(value);
				break;
			default:
				std::cerr << "Error\nScalar value for " << value << " not found\n";
				break;
		}
}
