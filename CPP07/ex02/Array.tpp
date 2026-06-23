/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:30:12 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/16 11:51:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	n = 0;
	elements = NULL;
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template <typename T>
Array<T>::Array(const unsigned int n): n(n)
{
	elements = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other): n(other.size())
{
	elements = NULL;
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete []elements;
		n = other.size();
		elements = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			elements[i] = other[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int idx)
{
	if (idx >= 0 && idx < n)
		return elements[idx];
	else
		throw Array<T>::IndexOutOfBoundsException();
}

template <typename T>
const T &Array<T>::operator[](const unsigned int idx) const
{
	if (idx >= 0 && idx < n)
		return elements[idx];
	else
		throw Array<T>::IndexOutOfBoundsException();
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index Out Of Bounds";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return n;
}
