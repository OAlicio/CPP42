/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:12:37 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/03 16:26:51 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int	fPointVal;
		static const int fBits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &value);
		Fixed(const int integer);
		Fixed(const float floatVal);
		Fixed& operator=(const Fixed &value);
		static	int getFBits();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed &value);

#endif
