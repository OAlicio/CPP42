/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:29:40 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/25 11:42:04 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

std::string	replace(std::string &readStr, std::string &match, std::string &toReplace, size_t &pos)
{
	std::string	replaced;

	while (pos != std::string::npos)
	{
		replaced += readStr.substr(0, pos);
		replaced += toReplace;
		readStr = readStr.substr(pos + match.length(), readStr.length() - pos);
		pos = readStr.find(match);
	}
	if (!readStr.empty())
		replaced += readStr;
	replaced += "\n";
	return replaced;
}

void	readFromFile(std::ifstream &readFile, std::string &finalStr, const char **av)
{
	size_t		pos;
	std::string	readStr;
	std::string	toReplace;
	std::string	match;

	match = av[2];
	toReplace = av[3];
	while(!readFile.eof())
	{
		getline(readFile, readStr);
		pos = readStr.find(match);
		if (pos != std::string::npos)
		{
			finalStr += replace(readStr, match, toReplace, pos);
		}
		else
			finalStr += readStr + "\n";
	}
}

void	replacer(const char **av)
{
	std::ifstream	readFile;
	std::ofstream	writeFile;
	std::string		file;
	std::string		finalStr;

	file = av[1];
	readFile.open(file.c_str());
	if (!readFile.is_open())
	{
		std::cerr << "Error while opening the input file" << std::endl;
		return ;
	}
	readFile.peek();
	if (readFile.fail())
	{
		std::cerr << "Error while trying to read from: " + file << std::endl;
		return ;
	}
	readFromFile(readFile, finalStr, av);
	readFile.close();
	writeFile.open((file + ".replace").c_str());
	if (!writeFile.is_open())
	{
		std::cerr << "Error while creating the output file" << std::endl;
		return ;
	}
	writeFile << finalStr;
	writeFile.close();
}
