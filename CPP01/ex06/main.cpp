/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:35:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/24 16:39:19 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;
	std::string	complainment;

	switch(ac)
	{
		case 1:
			std::cout << "No problems means no job for Harl" << std::endl;
			break;
		case 2:
			complainment = av[1];
			harl.complain(complainment);
			break;
		default:
			std::cout << "Harl can only complain 1 problem at time" << std::endl;
			break;
	}
	return 0;
}
