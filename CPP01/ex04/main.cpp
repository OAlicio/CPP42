/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:33:51 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/24 17:46:48 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
		replacer((const char **)av);
	else
		std::cout << "Usage: <filename> <string to find> <string to replace>" << std::endl;
}
