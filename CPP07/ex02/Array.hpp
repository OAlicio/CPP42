/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:10:16 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/16 11:51:13 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <class T>
class Array
{
	private:
		T *elements;
		unsigned int n;
	public:
		Array();
		~Array();
		Array(const unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](const unsigned int);
		const T &operator[](const unsigned int) const;
		unsigned int size() const;
		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
