/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:12:37 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/04 12:50:49 by ofeverei         ###   ########.fr       */
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
		//=========operators overload==============
		//|       Assignment operator             |
		Fixed& operator=(const Fixed &value);
		//|       Comparison operators            |
		bool operator>(const Fixed &value) const;
		bool operator<(const Fixed &value) const;
		bool operator>=(const Fixed &value) const;
		bool operator<=(const Fixed &value) const;
		bool operator==(const Fixed &value) const;
		bool operator!=(const Fixed &value) const;
		//|       Arithmetic operators            |
		Fixed& operator+(const Fixed &value);
		Fixed& operator-(const Fixed &value);
		Fixed& operator*(const Fixed &value);
		Fixed& operator/(const Fixed &value);
		//|   Increment/Decrement(pre and post)   |
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		//|                                       |
		//=========================================
		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
		static	int getFBits();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed &value);

#endif
