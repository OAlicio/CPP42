/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:22:34 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/19 17:33:19 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &first, int value)
{
	typename T::iterator it = std::find(first.begin(), first.end(), value);

	if (it == first.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
