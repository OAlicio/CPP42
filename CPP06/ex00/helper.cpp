/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:06:21 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 17:07:25 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void convertBasec(const std::string &value)
{
	int		int_val;
	float	float_val;
	double	double_val;
	char	char_val;

	char_val = static_cast<char>(value[1]);
	int_val = static_cast<int>(char_val);
	float_val = static_cast<float>(char_val);
	double_val = static_cast<double>(char_val);
	std::cout << "char: ";
	if (std::isprint(char_val))
		std::cout << char_val << std::endl;
	else
		std::cout << "Non displayable" << std::endl; 
	std::cout << "int: " << int_val << std::endl;
	std::cout << "float: " << float_val << ".0f" << std::endl;
	std::cout << "double: " << double_val << ".0" << std::endl;
}

void convertBasei(const std::string &value)
{
	long	toInt;;
	int		int_val;
	float	float_val;
	double	double_val;
	char	char_val;

	toInt = static_cast<long>(std::strtol(value.c_str(), NULL, 10));
	if (toInt >= INT_MIN && toInt <= INT_MAX)
	{
		int_val = static_cast<int>(toInt);
		char_val = static_cast<char>(int_val);
		float_val = static_cast<float>(int_val);
		double_val = static_cast<double>(int_val);
		std::cout << "char: ";
		if (std::isprint(char_val))
			std::cout << char_val << std::endl;
		else
			std::cout << "Non displayable" << std::endl; 
		std::cout << "int: " << int_val << std::endl;
		std::cout << "float: " << float_val << ".0f" << std::endl;
		std::cout << "double: " << double_val << ".0" << std::endl;
	}
	else
		std::cerr << value << " can cause overflow/underflow\n";
}

void convertBasef(const std::string &value)
{
	long	toInt;
	double	toFloat;
	int		int_val;
	float	float_val;
	double	double_val;
	char	char_val;

	toFloat = static_cast<double>(std::strtod(value.c_str(), NULL));
	if (toFloat >= -FLT_MAX && toFloat <= FLT_MAX)
	{
		float_val = static_cast<float>(toFloat);
		int_val = static_cast<int>(float_val);
		toInt = static_cast<long>(float_val);
		char_val = static_cast<char>(float_val);
		double_val = static_cast<double>(float_val);
		std::cout << "char: ";
		if (float_val == static_cast<long>(float_val))
		{
			if (std::isprint(char_val))
				std::cout << char_val << std::endl;
			else
				std::cout << "Non displayable" << std::endl; 
			std::cout << "int: ";
			if (toInt >= INT_MIN && toInt <= INT_MAX)
				std::cout << int_val << std::endl;
			else
				std::cout << "impossible" << std::endl;
			std::cout << "float: " << float_val << ".0f" << std::endl;
			std::cout << "double: " << double_val << ".0" << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
			std::cout << "int: ";
			if (toInt >= INT_MIN && toInt <= INT_MAX)
				std::cout << int_val << std::endl;
			else
				std::cout << "impossible" << std::endl;
			std::cout << "float: " << float_val << "f" << std::endl;
			std::cout << "double: " << double_val << std::endl;
		}
	}
	else
		std::cerr << value << " can cause overflow/underflow\n";
}

void convertBased(const std::string &value)
{
	int		int_val;
	long	toInt;
	float	float_val;
	double	double_val;
	char	char_val;

	double_val = static_cast<double>(std::strtod(value.c_str(), NULL));
	float_val = static_cast<float>(double_val);
	toInt = static_cast<long>(double_val);
	int_val = static_cast<int>(double_val);
	char_val = static_cast<char>(double_val);
	std::cout << "char: ";
	if (double_val == static_cast<long>(double_val))
	{
		if (std::isprint(char_val))
			std::cout << char_val << std::endl;
		else
			std::cout << "Non displayable" << std::endl; 
		std::cout << "int: ";
		if (toInt >= INT_MIN && toInt <= INT_MAX)
			std::cout << int_val << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << float_val << ".0f" << std::endl;
		std::cout << "double: " << double_val << ".0" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (toInt >= INT_MIN && toInt <= INT_MAX)
			std::cout << int_val << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << float_val << "f" << std::endl;
		std::cout << "double: " << double_val << std::endl;
	}
}

std::string trim(const std::string &str)
{
    const std::string whitespace = " \t\n\r\f\v";
    const size_t strBegin = str.find_first_not_of(whitespace);
    
    if (strBegin == std::string::npos)
        return "";

    const size_t strEnd = str.find_last_not_of(whitespace);
    const size_t strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
