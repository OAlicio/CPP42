/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:35:40 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/16 11:26:13 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *arr, const size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	iter(T *arr, const size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

//Test template
template <typename T>
void print(const T &val)
{
    std::cout << val << "\n";
}
 
template <typename T>
void increment(T &val)
{
    ++val;
}
 
template <typename T>
void doubleVal(T &val)
{
    val *= 2;
}
 

#endif
