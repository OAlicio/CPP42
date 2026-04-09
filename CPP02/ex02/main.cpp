/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:33:38 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/05 11:00:36 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a(2);
	Fixed b(5);

	a = a / b;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	/*std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	*/
	std::cout << a << std::endl;
	return 0;
}
