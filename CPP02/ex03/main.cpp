/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:33:38 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/05 11:04:19 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	const Point a(0.0f, 0.0f);
	const Point b(0, 9);
	const Point c(9.0f, 10.0f);
	const Point point(8, 9);

	if (bsp(a, b, c, point))
		std::cout << "\nThe point is inside\n" << std::endl;
	else
		std::cout << "\nThe point is outside\n" << std::endl;
}
