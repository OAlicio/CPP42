/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:19:18 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 16:48:35 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();

	public:
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		static uintptr_t	serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
