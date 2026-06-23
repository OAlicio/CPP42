/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:22:40 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/16 11:21:08 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &min(T &a, T &b)
{
	if (a > b)
		return b;
	else if (b > a)
		return a;
	return b;
}

template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
	return b;
}

#endif
