/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:59:53 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/09 14:44:17 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void	upper(std::string &str)
{
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	std::string	str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < ac)
		{
			str = av[i];
			upper(str);
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
