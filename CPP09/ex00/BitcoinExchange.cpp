/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:50:35 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/25 16:48:43 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : fileName("") {}

BitcoinExchange::~BitcoinExchange()
{
	if (bitFile.is_open())
		bitFile.close();
}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	fileName = file;
	this->open(fileName);
}

void BitcoinExchange::open(const std::string file)
{
	if (fileName != file)
		fileName = file;
	if (bitFile.is_open())
		bitFile.close();
	bitFile.open(fileName.c_str());
	if (!bitFile)
		throw std::runtime_error("Invalid DB file: " + file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
	}
	return *this;
}

const std::string BitcoinExchange::getFStream() const
{
	return fileName;
}

bool isDbHeader(std::string &header)
{
	if (header == "date,exchange_rate")
		return true;
	return false;
}

bool isFileHeader(std::string &header)
{
	if (header == "date | value")
		return true;
	return false;
}

void	BitcoinExchange::loadDb() 
{
	std::string data;
	std::string key;
	std::string value;

	if (!bitFile)
		return ;
	std::getline(bitFile, data);
	if (!isDbHeader(data))
	{
		std::cerr << "Invalid header => " << data << std::endl;
		return ;
	}
	while (std::getline(bitFile, data))
	{
		std::stringstream ss(data);
		while (std::getline(ss, key, ','))
		{
			std::getline(ss, value, ',');
			this->m[key] = std::strtod(value.c_str(), NULL);
		}
		ss.clear();
		ss.str("");
	}
}

bool	isValidInput(std::string &str)
{
	bool dec = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (i > 0 && i < str.size() - 1 && str[i] == '.' && !dec)
		{
			dec = true;
			continue ;
		}
		if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		{
			std::cerr << "Error: not a valid value => " << str << std::endl;
			return false;
		}
		if (str[i] == '-')
		{
			std::cerr << "Error: not a positive number.\n"; 
			return false;
		}
	}
	return true;
}

void	BitcoinExchange::exchange(const std::string file)
{
	std::ifstream exfile(file.c_str());
	std::string data;
	std::string key;
	std::string value;
	char token;

	if (!exfile)
		throw std::runtime_error("Error while opening file: " + file);
	token = ' ';
	std::getline(exfile, data);
	if (!isFileHeader(data))
	{
		std::cerr << "Invalid header => " << data << std::endl;
		return ;
	}
	while (std::getline(exfile, data))
	{
		std::stringstream ss(data);
		while (std::getline(ss, key, token))
		{
			std::getline(ss, value, token);
			if (value != "|")
			{
				std::cerr << "Error: bad input => " << data << std::endl;
				break ;
			}
			value.clear();
			std::getline(ss, value, token);
			if (value.empty())
			{
				std::cerr << "Error: bad input => " << data << std::endl;
				break ;
			}
			else if (!isValidInput(value))
				break ;
			std::map<std::string, double>::iterator kv = m.lower_bound(key);

			if (kv == m.begin() && kv->first != key)
			{
				std::cout << "Warning: No date for " << key
					<< " found\nUsing the lowest one " << m.begin()->first << std::endl;
				std::cout << "Value: " << value << std::endl;
				kv = m.begin();
			}
			else if (kv == m.end())
			{
				std::cout << "Warning: No date for " << key
					<< " found\nUsing the greatest one " << (--m.end())->first << std::endl;
				kv = --m.end();
			}
			else if (kv->first != key && kv != m.begin())
				--kv;
			float val = std::strtod(value.c_str(), NULL);
			if (val > 1000)
			{
				std::cerr << "Error: too large number.\n";
				break ;
			}
			else if (val <= 0)
			{
				std::cerr << "Error: not a positive number.\n";
				break ;
			}
			std::cout << key << " " << value <<" => ";
			double res = val * kv->second;
			std::cout << res << std::endl;
			ss.clear();
			ss.str("");
		}
	}
}
