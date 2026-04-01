/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:17:30 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/12 17:47:52 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	displayInterface(PhoneBook &ph, int inLoop)
{
	int			tot;

	std::cout << "\033[0m";
	std::cout << "\033[38;2;0;255;255m";
	if (!inLoop)
		std::cout << "|==========WELCOME TO PHONE BOOK==========|"<< std::endl;
	else
		std::cout << "|=========================================|"<< std::endl;
	tot = 0;
	if (ph.getIndex() < 9)
		tot = ph.getIndex();
	std::cout << "|         USE ADD, SEARCH OR EXIT         |\n|        TOTAL SAVED CONTACTS: [" << tot << "/8]      |" << std::endl;
	std::cout << "|=========================================|"<< std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[38;2;210;220;220m";
}

int	main(void)
{
	std::string	prompt;
	std::string	idx;
	PhoneBook	ph;

	/*	Maybe
	*	std::signal(SIGINT, SIG_IGN);
	*/
	
	displayInterface(ph, 0);
	while (!ph.isFinish())
	{
		std::cout << "> ";
		std::getline(std::cin, prompt);
		if (std::cin.fail())
		{
			std::cout << "\nCTRL+D Pressed\nExiting..." << std::endl;
			break ;
		}
		else if (prompt.empty())
			continue ;
		if (!prompt.compare("ADD"))
		{
			ph.addContact();
		}
		else if (!prompt.compare("SEARCH"))
		{
			if (ph.getIndex() > 0)
			{
				ph.displayContacts();
				ph.displayIdxContact();
			}
			else
				std::cout << "Phone Book is empty" << std::endl;
		}
		else if (!prompt.compare("EXIT"))
		{
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		else
			std::cout << "Command Not Found" << std::endl;
		if (ph.isFinish())
		{
			std::cout << "\nCTRL+D Pressed\nExiting..." << std::endl;
			break ;
		}
		prompt.clear();
		displayInterface(ph, 1);
	}
}
