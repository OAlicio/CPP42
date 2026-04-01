/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:15:56 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/24 12:35:04 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde;
	int		i;

	if (N <= 0)
		return NULL;
	horde = new (std::nothrow) Zombie[N];
	if (horde == NULL)
		return NULL;
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (&horde[0]);
}
