/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:50:35 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/23 17:37:54 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file)
{
	fileName = file;
	bitFile = std::ifstream(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->bitFile = other.getFStream();
	return *this;
}

std::ifstream BitcoinExchange::getFStream() const
{
	return std::ifstream(fileName);
}

void	BitcoinExchange::Exchange() 
{
	std::string data;
	std::string word;

	while (std::getline(bitFile, data, ','))
	{
		std::stringstream ss(data);
		while (ss >> word)
			std::cout << word << std::endl;
		ss.clear();
		ss.str("");
	}
}
