/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:23:42 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/01 10:29:22 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data *result = reinterpret_cast<Data *>(raw);
	return result;
}
