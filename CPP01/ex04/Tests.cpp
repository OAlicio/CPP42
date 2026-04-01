/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:18:01 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/25 11:48:58 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main()
{
	{
		const char *str[] = {"./testsed", "test.txt", "This", "That"};
		const char **av = str;
		std::ofstream	outputFile;
		std::string		toFile;
	
		std::cout << "==================================================================================" << std::endl;
		toFile = "Hello\nThis is a test file\n You can edit this line";
		std::cout << "test.txt content:\n|\n " + toFile + " \n|\n " + "Replacing 'This' to 'That'" << std::endl;
		outputFile.open("test.txt");
		outputFile << toFile;
		outputFile.close();
		replacer(av);
	}
	{
		const char *str[] = {"./testsed", "test2.txt", "AA", "$"};
		const char **av = str;
		std::ofstream	outputFile;
		std::string		toFile;

		std::cout << "==================================================================================" << std::endl;
		toFile = "AAaAAAaAAaaAaAAaa\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaAA\n You cAAn edit this line";
		std::cout << "test.txt content:\n|\n " + toFile + "\n|\n" + "Replacing 'AA' to '$'" << std::endl;
		outputFile.open("test2.txt");
		outputFile << toFile;
		outputFile.close();
		replacer(av);
	}
	{
		std::cout << "==================================================================================" << std::endl;
		const char *str[] = {"./testsed", "tests.txt", "This", "That"};
		const char **av = str;
		std::cout << "File that doesnt exist" << std::endl;
		replacer(av);
	}
	{
		std::cout << "==================================================================================" << std::endl;
		std::cout << "Trying to read from a directory" << std::endl;
		const char *str[] = {"./testsed", ".", "This", "That"};
		const char **av = str;
		replacer(av);
	}
}
