/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:19:36 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/19 17:32:26 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &first, int value);

#include "easyfind.tpp"
#endif
