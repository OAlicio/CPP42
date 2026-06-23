/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:57:49 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 16:42:06 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **ag)
{
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: " << ag[0] << " <value>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(ag[1]);
	return (0);
}
