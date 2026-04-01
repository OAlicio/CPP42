/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:12:37 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/04 12:53:20 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int	fPointVal;
		static const int fBits;

	public:
		//=====Ad-Hoc Polymorphism======
		Fixed();
		~Fixed();
		Fixed(Fixed &value);
		Fixed& operator=(Fixed &value);
		//==============================
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif
